/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:14:22 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/04 14:05:57 by ohadmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct	s_argformat
{
	// ft_printf return
	int	count;
	// flag status
	int	sign;
	// count of printed pre flag application
	int	s_len;

	// flags indicator
	int	sum;
	int	space;
	int	dash;
	int	zero;
	int	hash;
	int	width;
	int	precision;
}		t_argformat;

int		ft_printf(const char *str, ...);
int		flag_parser(const char *str, t_argformat *total);
int		format_handler(t_argformat *total, const char format, va_list args);
char	*check_valid_format(const char *str, t_argformat *total);

// utils
void	ft_printc(t_argformat *total, char n);
char	*ft_strchr(char *str, char set);

#endif
