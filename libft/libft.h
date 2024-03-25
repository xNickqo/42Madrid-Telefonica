/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:25:10 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/25 17:21:08 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H	
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>

//Prototipos de las funciones
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *dest, int value, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t len);
unsigned int		ft_strlcpy(char *dest, const char *src, size_t destsize);
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
char    		*ft_memchr(const char *str, int c, size_t n);
int     		ft_memcmp(const void *s1, const void *s2, size_t n);
char    		*ft_strstr(char *str, char *to_find, size_t len);
int			ft_atoi(char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *str);

#endif
