# Nombre del archivo de salida
NAME = juego

# Directorios
MLX_DIR = ./minilibx/minilibx-linux
GNL_DIR = ./GNL
PRINTF_DIR = ./FT_PRINTF
SRC_DIR = .
OBJ_DIR = ./OBJ

# Archivos fuente
SRC = $(wildcard $(SRC_DIR)/*.c)
GNL_SRC = $(wildcard $(GNL_DIR)/*.c)
PRINTF_SRC = $(wildcard $(PRINTF_DIR)/*.c)

ALL_SRC = $(SRC) $(GNL_SRC) $(PRINTF_SRC)

OBJ = $(ALL_SRC:%.c=$(OBJ_DIR)/%.o)

# Compilador
CC = gcc

# Flags que se le pasaran al compilador
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) -I$(GNL_DIR) -I$(SRC_DIR) -I$(PRINTF_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Construye la librería principal
all: $(NAME)

# Compila el ejecutable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

# Compila cada archivo fuente en un archivo objeto
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Elimina los archivos objeto
clean:
	rm -rf $(OBJ_DIR)

# Elimina tanto los objetos como la libreria
fclean: clean
	rm -f $(NAME)

# Elimina todo y lo vuelve a construir
re: fclean all

# Indica que las reglas no son archivos reales
.PHONY: all bonus clean fclean re

