/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:25:10 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/21 17:31:34 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H	
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>

//Prototipos de las funciones
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *dest, int value, size_t len);
void			ft_bzero(void *s, size_t n);
//ft_memcpy
void			*ft_memmove(void *dest, const void *src, size_t len);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t destsize);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				*ft_strncmp(char *s1, char *s2, unsigned int n);
//ft_memchr
//ft_memcmp
//ft_strnstr
int				ft_atoi(char *str);
//calloc
//strdup

#endif
