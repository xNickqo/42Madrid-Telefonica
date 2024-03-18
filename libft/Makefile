# Nombre del archivo de salida
NAME = libft.a

# Todos los archivos ft_*.c
SRCS = $(wildcard ft_*.c)

# Objetos generados a partir de los archivos fuente
OBJS = $(SRCS:.c=.o)

# Compilador
CC = gcc

# Flags que se le pasaran al compilador
CFLAGS = -Wall -Wextra -Werror

# Reglas

# Construye la libreria
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

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
.PHONY: all clean fclean re

