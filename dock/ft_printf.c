/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:19:47 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/19 17:01:02 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_handler(t_lc *total, va_list args, const char format)
{
	if (format == 'c' && total->check != -1)
		ft_putchar(&*total, va_arg(args, int));
	else if (format == 's' && total->check != -1)
		ft_putstr(&*total, va_arg(args, char *));
	else if (format == 'p' && total->check != -1)
		ft_putptr(&*total, va_arg(args, void *));
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

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_lc	total;
	int		i;

	total = (t_lc){};
	va_start(args, str);
	i = 0;
	while (str[i] != '\0' && total.check != -1)
	{
		while (str[i] && str[i] != '%' && total.check != -1)
			ft_putchar(&total, str[i++]);
		if (str[i] == '%' && str[i] && total.check != -1)
		{
			if (format_handler(&total, args, str[++i]) != -1)
				i++;
		}
	}
	if (total.check == -1)
		return (-1);
	return (total.len);
}

#include <stdio.h>

int	main()
{
//printf("/// FT_PRINTF ///\n");
	int	res = printf(0);
	printf("%d\n",res);
//	printf("\n");
//
//	printf("/// OS_PRINTF ///\n");
	//printf(0);
//	printf("\n");
//
////	printf("ft_printf returns = %d\n", res);
//	printf("OS_printf returns = %d\n", res2);
	
	return (0);
}
