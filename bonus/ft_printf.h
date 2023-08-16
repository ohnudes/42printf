/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:14:22 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/16 21:01:01 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct	s_argformat
{
	char	*spec;	// *spec == spec ocurrence
	int		count;	// ft_printf return

	// IF FLAGS DETECTED
	int		flags;	// flag used in printc to count for total len.
	int		s_len;

	// flags indicator
	int		sum;
	int		space;
	int		dash;
	int		zero;
	int		hash;
	int		width;
	int		precision;
}			t_argformat;

int		ft_printf(const char *str, ...);

// checking for flags
void	flag_parser(t_argformat *total, va_list args, char *start, char *set);
char	*check_valid_format(const char *str, int *flags);

// no flags
int		format_handler(t_argformat *total, va_list args, const char format);

// utils
char	*ft_strchr(const char *str, char set);
void	ft_printc(t_argformat *total, char n);
void	ft_prints(t_argformat *total, char *s);

// print format
void	ft_printp(t_argformat *total, void *ptr);
void	ft_printdi(t_argformat *total, int	i);
void	ft_printu(t_argformat *total, unsigned int u);
void	ft_printx_lc(t_argformat *total, unsigned int x);
void	ft_printx_uc(t_argformat *total, unsigned int X);

// flag utils
void	ft_sumflag(t_argformat *total);

#endif
