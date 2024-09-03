# Nombre del archivo de salida
NAME = GAME.exe

# Directorios
MLX_DIR = ./minilibx/minilibx-linux
GNL_DIR = ./GNL
PRINTF_DIR = ./FT_PRINTF
SRC_DIR = .
OBJ_DIR = ./OBJ

# Archivos fuente
SRC = 	$(SRC_DIR)/f_dfs.c \
		$(SRC_DIR)/f_draw_map.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/f_handle_keys.c \
		$(SRC_DIR)/f_is_valid_path.c \
		$(SRC_DIR)/f_map_validator.c \
		$(SRC_DIR)/f_player_move.c \
		$(SRC_DIR)/f_read_map.c 

GNL_SRC = 	$(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c

PRINTF_SRC = 	$(PRINTF_DIR)/ft_char.c \
				$(PRINTF_DIR)/ft_int.c \
				$(PRINTF_DIR)/ft_itoa.c \
				$(PRINTF_DIR)/ft_printf.c \
				$(PRINTF_DIR)/ft_ptr.c \
				$(PRINTF_DIR)/ft_str.c \
				$(PRINTF_DIR)/ft_strlen.c \
				$(PRINTF_DIR)/ft_uitoa_hex.c \
				$(PRINTF_DIR)/ft_uitoa.c \
				$(PRINTF_DIR)/ft_unsignedint.c \
				$(PRINTF_DIR)/ft_x.c \
				$(PRINTF_DIR)/ft_xupper.c

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

