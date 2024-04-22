/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:25:10 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/22 17:54:16 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *format, ...);
void	ft_char(va_list args, int *count);
void	ft_str(va_list args, int *count);
void	ft_ptr(va_list args, int *count);
void	ft_int(va_list args, int *count);
void	ft_unsignedint(va_list args, int *count);
//void	ft_x(va_list args, int *count);

size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);

#endif
