# **************************************************************************** #
#                                    Makefile                                  #
# **************************************************************************** #

# Nombre del archivo de salida
NAME = pipex

# 🗂️ Directorios
LIBFT_DIR 	= ./LIBFT
PRINTF_DIR 	= ./FT_PRINTF
SRC_DIR 	= .
OBJ_DIR 	= ./OBJ

# 📂 Archivos fuente
SRC 		= $(wildcard $(SRC_DIR)/*.c)
PRINTF_SRC 	= $(wildcard $(PRINTF_DIR)/*.c)
LIBFT_SRC 	= $(wildcard $(LIBFT_DIR)/*.c)

ALL_SRC 	= $(LIBFT_SRC) $(PRINTF_SRC) $(SRC)

# 🧱 Archivos objeto
OBJ 		= $(ALL_SRC:%.c=$(OBJ_DIR)/%.o)

# ⚙️ Compilador y flags
CC 			= gcc
CFLAGS 		= -g -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(SRC_DIR)

# 🎨 Colores
GREEN       = \033[32m
RED         = \033[31m
YELLOW      = \033[1;33m
CYAN        = \033[36m
RESET       = \033[0m


# **************************************************************************** #
#                                   Reglas                                     #
# **************************************************************************** #

# 🔨 Construye el ejecutable principal
all: $(NAME)

# Compila el ejecutable
$(NAME): $(OBJ)
	@echo "$(CYAN)🔨 Compilando $(NAME)...$(RESET)"
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo "---------------------------------"
	@echo "$(GREEN) 	  COMPILADO	 	$(RESET)"
	@echo "---------------------------------"

# **************************************************************************** #

# 🧱 Compila los archivos fuente en objetos
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)⏳ Compilando $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #

# 🧹 Limpia los archivos objeto
clean:
	@echo "$(RED) Limpiando archivos objeto...🧹$(RESET)"
	@rm -rf $(OBJ_DIR)

# **************************************************************************** #

# 🗑️ Limpia todos los archivos (objetos y ejecutables)
fclean: clean
	@echo "$(RED) Eliminando $(NAME)...🗑️$(RESET)"
	@rm -f $(NAME)

# **************************************************************************** #

# ♻️ Limpia y reconstruye todo
re: fclean all

# **************************************************************************** #

# 📌 Indica que las reglas no son archivos reales
.PHONY: all bonus clean fclean re

