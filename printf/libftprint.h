/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:25:10 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/19 15:14:17 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(char const *format, ...);
void	ch_format(va_list args, int *count);
void	str_format(va_list args, int *count);

#endif
