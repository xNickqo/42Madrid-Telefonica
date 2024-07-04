/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 02:36:54 by niclopez          #+#    #+#             */
/*   Updated: 2024/07/05 01:02:02 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>

# define MAX_FILAS 100
# define MAX_COLUMNAS 100
# define TILE_SIZE 50

/*Estructuras*/
typedef	struct
{
	int	x;
	int	y;
	int	collected;
} t_player;

typedef struct
{
	int	x;
	int	y;
} t_pos;

typedef struct
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	char	map[MAX_FILAS][MAX_COLUMNAS];
	int		num_filas;
	int		num_columnas;
	t_pos	start;
	t_pos	end;
	int		obj_count;

    // Imgs
	int		img_width;
	int		img_height;
	void	*wall;
	void	*floor;
	void	*player;
	void	*player_front;
	void	*player_right;
	void	*player_left;
	void	*player_back;
	void	*exit;
	void	*collectible;

    //Player
	t_player	p;
	int			move_count;
} t_game;

/*MAIN*/
void	is_ber_file(int argc, char *argv[]);

/*Keys*/
int		handle_exit(t_game *game);
int		handle_key(int key, t_game *game);

/*draw_map*/
void	load_images(t_game *game);
void	free_images(t_game *game);
void	draw_tile(t_game *game, int i, int j);
void	draw_map(t_game *game);

/*valid_way*/
//void	print_visited(bool visited[MAX_FILAS][MAX_COLUMNAS], int num_filas, int num_columnas);
bool	is_valid_pos(t_game *game, int x, int y, bool visited[MAX_FILAS][MAX_COLUMNAS]);
bool	dfs(t_game *game,  int x, int y, bool visited[MAX_FILAS][MAX_COLUMNAS], int *obj);
bool	is_valid_path(t_game *game);

/*read_map*/
int		open_file(char *filename);
void	read_map(char *filename, t_game *game);

/*valid_map*/
bool	has_duplicates(t_game *game);
bool	map_validator(t_game *game);
bool	is_rectangular(t_game *game);
bool	check_walls(t_game *game);
bool	check_counts(int start_count, int exit_count, int obj_count);

/*read_file*/
void	process_line(t_game *game, char *line);
void	read_file(int fd, t_game *game);

/*player_move*/
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

/*GNL*/
size_t	ft_strlen_gnl(char	*str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join(char *res, char *s1, char *s2);
char	*read_line(char *buffer);
char	*restbuff(char	*buffer);
char	*fd_error(char *buffer, char *line);
char	*get_next_line(int fd);

/*Printf*/
int		ft_printf(char const *format, ...);
void	ft_char(va_list args, int *count);
void	ft_str(va_list args, int *count);
void	ft_ptr(va_list args, int *count);
void	ft_int(va_list args, int *count);
void	ft_unsignedint(va_list args, int *count);
void	ft_x(va_list args, int *count);
void	ft_xupper(va_list args, int *count);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa_hex(unsigned int n, int letra);

#endif