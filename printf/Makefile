# Nombre del archivo de salida
NAME = libftprintf.a

LIBFT = libft/

LIBFT_NAME = libft.a

OBJS = ft_printf.o

OBJSBONUS =

# Compilador
CC = gcc

# Flags que se le pasaran al compilador
CFLAGS = -Wall -Wextra -Werror -I

# Reglas

# Construye la libreria principal
all: $(NAME)

$(NAME): $(OBJS)
	@make all -C $(LIBFT)
	@mv $(LIBFT_NAME) $(NAME) ||:
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

# Construye la libreria bonus
bonus: $(OBJSBONUS)
	ar rc $(NAME) $(OBJSBONUS)

# Compila cada archivo fuente en un archivo objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Elimina los archivos objeto
clean:
	@make clean -C $(LIBFT)
	rm -rf *.o

# Elimina tanto los objetos como la libreria
fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

# Elimina todo y lo vuelve a construir
re: fclean all

# Indica que las reglas no son archivos reales
.PHONY: all bonus clean fclean re

