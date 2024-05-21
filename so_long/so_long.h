#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
#include <stdbool.h>

#define MAX_FILAS 100
#define MAX_COLUMNAS 100
#define TILE_SIZE 32

/*Estructuras*/
typedef struct
{
    void    *mlx;
    void    *window;
    int     width;
    int     height;
    char    map[MAX_FILAS][MAX_COLUMNAS];
    int     num_filas;
    int     num_columnas;
} t_game;


/*Funciones*/
int     handle_key(int key, t_game *game);
void    draw_tile(t_game *game, int x, int y, int color);
void    draw_map(t_game *game);

bool    has_duplicates(t_game *game);
bool    map_validator(t_game *game);
void    read_map(char *filename, t_game *game);

/*GNL*/
size_t	ft_strlen(char	*str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join(char *res, char *s1, char *s2);
char	*read_line(char *buffer);
char	*restbuff(char	*buffer);
char	*fd_error(char *buffer, char *line);
char	*get_next_line(int fd);

#endif