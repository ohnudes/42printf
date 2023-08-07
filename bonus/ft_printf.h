/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:14:22 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/07 19:27:25 by nmaturan         ###   ########.fr       */
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

	// IF FLAGS DETECTED
	int	precount;
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

// checking for flags
int		flag_parser(t_argformat *total, const char *str);
char	*check_valid_format(const char *str);
void	flag_sum_space(const char *str, t_argformat *total);

// no flags
int		format_handler(t_argformat *total, va_list args, const char format);

// utils
char	*ft_strchr(const char *str, int set);
void	ft_printc(t_argformat *total, char n);
void	ft_prints(t_argformat *total, char *s);

// print format
void	ft_printp(t_argformat *total, void *ptr);
void	ft_printdi(t_argformat *total, int	i);
void	ft_printu(t_argformat *total, unsigned int u);
void	ft_printx_lc(t_argformat *total, unsigned int x);
void	ft_printx_uc(t_argformat *total, unsigned int X);

#endif
