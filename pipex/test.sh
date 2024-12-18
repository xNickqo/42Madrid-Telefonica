#!/bin/bash

# **************************************************************************** #
#                                   Configuración                              #
# **************************************************************************** #

# Define colores para los mensajes
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
CYAN='\033[0;36m'
YELLOW='\033[0;33m'
NC='\033[0m' # Sin color

# Separador visual
SEP_LINE="${YELLOW}--------------------------------------------------${NC}"

# **************************************************************************** #
#                                  Funciones                                   #
# **************************************************************************** #

# Imprime los contenidos de los archivos para compararlos
print_files() {
    echo -e "${SEP_LINE}"
    echo -e "${BLUE}[Pipex Output]:${NC}"
    cat "$1"
    echo -e "${SEP_LINE}"
    echo -e "${CYAN}[Expected Output]:${NC}"
    cat "$2"
    echo -e "${SEP_LINE}"
}

# Compara las salidas de pipex y bash
compare_outputs() {
    local out_pipex="$1"
    local out_bash="$2"
    local transformer="$3"

    # Si los archivos no existen
    if [ ! -f "$out_pipex" ] || [ ! -f "$out_bash" ]; then
        echo -e "${RED}[KO] Files do not exist or are inaccessible.${NC}"
        return 1
    fi

    # Transforma las salidas si se pasa un transformador
    if [ "$transformer" != "" ]; then
        eval "$transformer" < "$out_pipex" > pipex_transformed
        mv pipex_transformed "$out_pipex"

        eval "$transformer" < "$out_bash" > bash_transformed
        mv bash_transformed "$out_bash"
    fi

    # Compara los archivos de salida
    if diff -q "$out_pipex" "$out_bash" >/dev/null; then
        echo -e "${GREEN}[OK] Outputs match.${NC}"
    else
        echo -e "${RED}[KO] Outputs differ:${NC}"
        print_files "$out_pipex" "$out_bash"
    fi
}

# Realiza una prueba específica
test_pipex() {
    local infile="$1"
    local cmd1="$2"
    local cmd2="$3"
    local outfile="pipex_out"
    local transformer="$4"

    echo -e "${BLUE}Testing: '${cmd1}' | '${cmd2}'${NC}"

    # Verifica que el ejecutable de pipex exista
    if [ ! -f "pipex" ]; then
        echo -e "${RED}[KO] pipex binary does not exist.${NC}"
        return 1
    fi

    # Ejecuta pipex y mide el tiempo
    start_time=$(date +%s.%N)
    ./pipex "$infile" "$cmd1" "$cmd2" "$outfile" 2>/dev/null
    end_time=$(date +%s.%N)
    pipex_duration=$(echo "$end_time - $start_time" | bc)
    pipex_duration=$(printf "%.4f" "$pipex_duration")

    # Ejecuta el equivalente en bash y mide el tiempo
    start_time=$(date +%s.%N)
    < "$infile" bash -c "$cmd1 | $cmd2" > bash_out 2>/dev/null
    end_time=$(date +%s.%N)
    bash_duration=$(echo "$end_time - $start_time" | bc)
    bash_duration=$(printf "%.4f" "$bash_duration")

    # Muestra los tiempos
    echo -e "Pipex: ${CYAN}$pipex_duration${NC}s | Bash: ${CYAN}$bash_duration${NC}s"

    # Compara salidas
    compare_outputs "$outfile" "bash_out" "$transformer"

    echo -e "${SEP_LINE}"
}

# **************************************************************************** #
#                                   Pruebas                                    #
# **************************************************************************** #

run_tests() {
    # Pruebas básicas: comandos simples
    test_pipex "infile" "cat" "cat"
    test_pipex "infile" "grep a" "wc -l"
    test_pipex "infile" "sort" "uniq"
    test_pipex "infile" "tr 'a-z' 'A-Z'" "cat"

    # Pruebas de tiempos: procesos largos y cortos
    test_pipex "infile" "sleep 2" "cat"
    test_pipex "infile" "cat" "sleep 2"
    test_pipex "infile" "sleep 3" "sleep 2"

    # Pruebas de procesos fallidos
    test_pipex "infile" "invalid_command" "cat"
    test_pipex "infile" "cat" "invalid_command"
    test_pipex "infile" "invalid_command1" "invalid_command2"


    # Pruebas de edge cases: entrada vacía o sin permisos
    touch empty_infile
    chmod 000 empty_infile
    test_pipex "empty_infile" "cat" "wc -l"
    rm -f empty_infile

    # Pruebas de gran volumen
    yes "test line" | head -n 100000 > large_infile
    test_pipex "large_infile" "cat" "wc -l"
    rm -f large_infile

    # Pruebas de errores comunes: nombres de archivos incorrectos
    test_pipex "nonexistent_file" "cat" "wc -l"
}

# **************************************************************************** #
#                                   Main                                       #
# **************************************************************************** #

run_tests
