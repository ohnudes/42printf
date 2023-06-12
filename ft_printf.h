/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:42:18 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/12 11:47:29 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef	FT_PRINTF_H 
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int			ft_printf(const char *str, ...);
static int	format_handler(va_list args, const char format);

int	ft_putchar();
int	ft_putstr();
int	ft_putptr();
int	ft_putnbr();
int	ft_putunbr();
int	ft_puthex();

#endif // DEBUG
