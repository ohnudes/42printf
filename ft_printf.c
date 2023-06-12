/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:40:54 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/12 11:42:05 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include "libft.h"
#include "ft_printf.h"


static int	format_handler(va_list args, const char	format)
{
	int	handler;

	handler =  0;
	if (format == 'c')
		handler += ft_putchar(va_arg(args, int));
	else if (format == 's') 
		handler += ft_putstr(va_arg(args, int));
	else if (format == 'p')
		handler += ft_putptr(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		handler += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		handler += ft_putunbr(va_arg(args, int));
	else if (format == 'x')
		handler += ft_puthex(va_arg(args, int));
	else if (format == '%')
		handler += ft_putchar('%');

	return (handler);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		format_len;
	va_list	args;

	i = 0;
	format_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			format_len += format_handler(args, str[i + 1]);
			i++;
		}
		else
			format_len += ft_putchar(str[i]);
		i++;

	}
	va_end(args);
	return (format_len);
}

int	main(int argc, char **argv)
{

	return (0);
}
