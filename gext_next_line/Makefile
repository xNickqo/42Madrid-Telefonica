# Nombre del archivo de salida
NAME = libftprintf.a

# Lista de archivos de origen
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
# OBJSBONUS =

# Compilador
CC = gcc

# Flags que se le pasaran al compilador
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=100

# Construye la libreria principal
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "ft_print compiled!"

# # Construye la libreria bonus
# bonus: $(OBJSBONUS)
# 	ar rc $(NAME) $(OBJSBONUS)

# Compila cada archivo fuente en un archivo objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Elimina los archivos objeto
clean:
	rm -rf *.o

# Elimina tanto los objetos como la libreria
fclean: clean
	rm -f $(NAME)

# Elimina todo y lo vuelve a construir
re: fclean all

# Indica que las reglas no son archivos reales
.PHONY: all bonus clean fclean re

