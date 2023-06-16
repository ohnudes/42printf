/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:19:47 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/16 17:53:40 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_handler(t_lc *total, va_list args, const char format)
{
	if (format == 'c')
		total->len = ft_putchar(&*total, va_arg(args, int));
	else if (format == 's')
		total->len = ft_putstr(&*total, va_arg(args, char *));
	else if (format == 'p')
		total->len = ft_putptr(&*total, va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		total->len = ft_putint(&*total, va_arg(args, int));
	else if (format == 'u')
		total->len = ft_putuint(*&total, va_arg(args, unsigned int));
	else if (format == 'x')
		total->len = ft_put_l_hex(&*total, va_arg(args, unsigned int ));
	else if (format == 'X')
		total->len = ft_put_u_hex(&*total, va_arg(args, unsigned int));
	else if (format == '%')
		total->len = ft_putchar(&*total, '%');
	if (total->check == -1)
		return (-1);
	return (total->len);
}

char	*ft_strchr(t_lc *total, const char *str, char c)
{
	char	*ref;
	size_t	i;

	if (!str)
	{
		write(1, "(null)", 6);
		total->check = 1;
		return (0);
	}
	ref = (char *) str;
	i = 0;
	while (ref[i] != c && ref[i])
		i++;
	return (&ref[i]);
}

/* Idea:
 * 1. Deal with split logic for multiple % intercalated with normal strings.
 *		1.2 - return depending of struct rather than checking at every level.
 * 2. Deal with different formats.
 *
 */
// checkear si es posible remplazar la funcion(ft_putchar dentro del while)
// por un format handler con el arg dado.

int	ft_printf(const char *str, ...) 
{
	va_list args;
	t_lc	total;
	char	*ref;
	
	total.len = 0;
	total.check = 0;
	va_start(args, str);
	ref = ft_strchr(&total, str, '%');
	while (str && total.check != 1)
	{
		while (str && str < ref  && total.check != 1)
		{
			total.len = ft_putchar(&total, *str); 
			str += total.len;
		}
		if (str == ref && total.check != 1)
		{
			total.len = format_handler(&total, args, *++str);
			str++;
			ref = ft_strchr(&total, str, '%');
		}
	}
	if (total.check == 1)
		return (-1);
	return (total.len);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	res = ft_printf("", argv[1]);
	int res2 = printf("", argv[1]);

	printf("ft_printf returns = %d\n", res);
	printf("OS_printf returns = %d\n", res);
	
	return (0);
}*/
