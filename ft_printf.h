/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:20:51 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/16 12:35:58 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_lc
{
	int			len;
	int			check;
}				t_lc;

int		ft_printf(const char *str, ...);
int		format_handler(t_lc *total, va_list args, const char format);
char	*ft_strchr(t_lc *total, const char *str, char c);

int		ft_putchar(t_lc *total, int c);
int		ft_putstr(t_lc *total, char *s);
int		ft_putptr(t_lc *total, unsigned long p);
int		ft_putint(t_lc *total, int i);
int		ft_putuint(t_lc *total, unsigned int u);
int		ft_put_l_hex(t_lc *total, unsigned int x);
int		ft_put_u_hex(t_lc *total, unsigned int X);


#endif // !FT_PRINTF_H
