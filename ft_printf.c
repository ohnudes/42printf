/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:40:54 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/12 20:02:57 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>


static int	format_handler(va_list args, const char	format)
{
	int	format_len;
	int	check;

	format_len =  0;
	if (format == 'c')
		format_len = ft_putchar(va_arg(args, int));
	else if (format == 's') 
		format_len = ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		format_len = ft_putptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		format_len = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		format_len = ft_putunbr(va_arg(args, unsigned int));
//	else if (format == 'x')
//		format_len = ft_putlhex(va_arg(args, unsigned int));
//	else if (format == 'X')
		//format_len = ft_putuhex(va_arg(args, long));
	else if (format == '%')
		format_len = ft_putchar('%');
	return (format_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		format_len;
	int		total;

	i = 0;
	format_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			format_len += format_handler(args, str[++i]);
		else
			format_len += ft_putchar(str[i]);
		i++;
		if (format_len  == -1)
			return (-1);
		else
			total += format_len;
	}
	va_end(args);
	return (total);
}

int	main(int argc, char **argv)
{
	ft_printf("%c",argv[1]);
	return (0);
}
