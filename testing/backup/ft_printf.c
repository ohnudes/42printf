/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:19:47 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/18 16:10:12 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	format_handler(t_lc *total, va_list args, const char format)
{
	if (format == 'c' && total->check != -1)
		ft_putchar(&*total, va_arg(args, int));
	else if (format == 's' && total->check != -1)
		ft_putstr(&*total, va_arg(args, char *));
	else if (format == 'p' && total->check != -1)
		ft_putptr(&*total, va_arg(args, unsigned long));
	else if ((format == 'd' || format == 'i') && total->check != -1)
		ft_putint(&*total, va_arg(args, int));
	else if (format == 'u' && total->check != -1)
		ft_putuint(*&total, va_arg(args, unsigned int));
	else if (format == 'x' && total->check != -1)
		ft_put_l_hex(&*total, va_arg(args, unsigned int ));
	else if (format == 'X' && total->check != -1)
		ft_put_u_hex(&*total, va_arg(args, unsigned int));
	else if (format == '%' && total->check != -1)
		ft_putchar(&*total, '%');
	if (total->check == -1)
		return (-1);
	return (0);
}

int	ft_strchr(t_lc *total, const char *str, char c)
{
	char	*ref;
	int		i;

	ref = (char *) str;
	if (!str)
	{
		ft_putstr(&*total, "(null)");
		return (total->len);
	}
	i = 0;
	while (ref[i] != c && ref[i])
		i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_lc	total;
	int		ref;
	int		i;

	total.len = 0;
	total.check = 0;
	va_start(args, str);
	ref = ft_strchr(&total, str, '%');
	i = 0;
	while (str[i] && total.check != -1)
	{
		while (str[i] && i < ref && total.check != -1)
			ft_putchar(&total, str[i]);
		if (str[i] && i == ref && total.check != -1)
		{
			format_handler(&total, args, str[++i]);
			if (str[i + 1])
				ref = i + ft_strchr(&total, (str + i), '%');
		}
	}
	if (total.check == -1)
		return (-1);
	return (total.len);
}

int	main()
{
	printf("/// FT_PRINTF ///\n");
	int	res = ft_printf("abc %s", "123");
	printf("\n");
	printf("/// OS_PRINTF ///\n");
	int res2 = printf("abc %s", "123");
	printf("\n");

	printf("ft_printf returns = %d\n", res);
	printf("OS_printf returns = %d\n", res);
	
	return (0);
}
