/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:20:51 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/15 16:35:38 by nmaturan         ###   ########.fr       */
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

int		ft_putchar(int	*check, int c);
int		ft_putstr(int *check, char *s);
int		ft_putptr(int *check, unsigned long p);
int		ft_putitoa(int *check, int i);
int		ft_putuitoa(int *check, unsigned int u);
int		ft_put_l_hex(int *check, unsigned int x);
int		ft_put_u_hex(int *check, unsigned int X);


#endif // !FT_PRINTF_H
