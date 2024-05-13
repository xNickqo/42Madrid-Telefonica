/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:42:08 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/13 22:23:19 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <unistd.h>

char	*read_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(1 + i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*restbuff(char	*buffer)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	i += (buffer[i] == '\n');
	new_buff = (char *)malloc(1 + ft_strlen(buffer) - i);
	if (!new_buff)
		return (NULL);
	j = 0;
	while (buffer[i + j])
	{
		new_buff[j] = buffer[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(buffer);
	return (new_buff);
}

char	*fd_error(char *buffer, char *line)
{
	free(line);
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			bytes_read;
	static char	*buffer[1024] = {NULL};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	line = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!line)
		return (NULL);
	while (!(ft_strchr(buffer[fd], '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
			return (fd_error(buffer[fd], line));
		line[bytes_read] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], line);
	}
	free(line);
	line = read_line(buffer[fd]);
	buffer[fd] = restbuff(buffer[fd]);
	return (line);
}

/* #define NUM_FILES 2

int main(void) {
    int fd[NUM_FILES]; // Descriptores de archivo
    char *line[NUM_FILES]; // Almacena las líneas leídas
    int i;

    fd[0] = open("ejemplo.txt", O_RDONLY);
    fd[1] = open("ejemplo1.txt", O_RDONLY);

    while (1) {
        int lines_read = 0;

		i = 0;
        while (i < NUM_FILES) {
            if (fd[i] != -1) {
                line[i] = get_next_line(fd[i]);
                if (line[i] != NULL) 
				{
					if(ft_strchr(line[i], '\n'))
					{
                    	printf("fd[%d] : %s", i, line[i]);
                    	lines_read++;
					}
					else
					{
						printf("fd[%d] : %s\n", i, line[i]);
						lines_read++;
					}
                }
				else
					close(fd[i]);
            }
			i++;
        }
        if (lines_read == 0) {
            break;
        }
    }
    return 0;
} */