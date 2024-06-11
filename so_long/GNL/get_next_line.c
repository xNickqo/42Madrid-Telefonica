/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:05:21 by niclopez          #+#    #+#             */
/*   Updated: 2024/06/11 18:53:29 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1


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
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	line = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!line)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
			return (fd_error(buffer, line));
		line[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	line = read_line(buffer);
	buffer = restbuff(buffer);
	return (line);
}

/* int main(void)
{
    int fd = open("ejemplo.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Linea leida: %s", line);
        free(line);
    }
    close(fd);
    return 0;
} */
