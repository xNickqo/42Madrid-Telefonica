# Nombre del archivo de salida
NAME = checker

# Directorios
LIBFT_DIR = ./LIBFT
PRINTF_DIR = ./FT_PRINTF
SRC_DIR = .
OBJ_DIR = ./OBJ

# Archivos fuente
SRC = $(SRC_DIR)/check_args.c \
      $(SRC_DIR)/list_utils.c \
      $(SRC_DIR)/main.c \
      $(SRC_DIR)/radix_sort.c \
      $(SRC_DIR)/simple_sort.c \
	  $(SRC_DIR)/push.c \
	  $(SRC_DIR)/reverse_rotate.c \
	  $(SRC_DIR)/rotate.c \
	  $(SRC_DIR)/swap.c \
	  $(SRC_DIR)/utils.c

PRINTF_SRC = $(PRINTF_DIR)/ft_printf.c \
      $(PRINTF_DIR)/ft_char.c \
      $(PRINTF_DIR)/ft_int.c \
      $(PRINTF_DIR)/ft_ptr.c \
      $(PRINTF_DIR)/ft_str.c \
	  $(PRINTF_DIR)/ft_uitoa.c \
	  $(PRINTF_DIR)/ft_uitoa_hex.c \
	  $(PRINTF_DIR)/ft_unsignedint.c \
	  $(PRINTF_DIR)/ft_x.c \
	  $(PRINTF_DIR)/ft_xupper.c \
	  $(PRINTF_DIR)/ft_itoa.c \
	  $(PRINTF_DIR)/ft_strlen.c

LIBFT_SRC = $(LIBFT_DIR)/ft_atoi.c \
      $(LIBFT_DIR)/ft_isdigit.c \
      $(LIBFT_DIR)/ft_putchar_fd.c \
      $(LIBFT_DIR)/ft_putendl_fd.c \
	  $(LIBFT_DIR)/ft_putnbr_fd.c \
	  $(LIBFT_DIR)/ft_split.c \
	  $(LIBFT_DIR)/ft_strchr.c \
	  $(LIBFT_DIR)/ft_striteri.c \
	  $(LIBFT_DIR)/ft_putstr_fd.c \
	  $(LIBFT_DIR)/ft_strlcpy.c

ALL_SRC = $(LIBFT_SRC) $(PRINTF_SRC) $(SRC)

OBJ = $(ALL_SRC:%.c=$(OBJ_DIR)/%.o)

# Compilador
CC = gcc

# Flags que se le pasaran al compilador
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(SRC_DIR)

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

