/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:42:18 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/12 18:03:31 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *str, ...);
static int	format_handler(va_list args, const char format);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long c);
int	ft_putnbr(int c);
int	ft_putunbr(unsigned int c);
//int	ft_putlhex(unsigned long c);
//int	ft_putuhex(unsigned long c);
char	*ft_itoa(int c);

#endif // DEBUG
