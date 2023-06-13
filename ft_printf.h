/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:42:18 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/13 19:42:47 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *str, ...);
int	format_handler(va_list args, const char	format);

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putptr(unsigned long p);
int	ft_putnbr(int d);
int	ft_puthex(unsigned int x);
//int	ft_putlhex(unsigned long c);
//int	ft_putuhex(unsigned long c);
char	*ft_itoa(int c);

#endif // DEBUG
