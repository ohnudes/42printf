/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:35 by nmaturan          #+#    #+#             */
/*   Updated: 2023/07/30 16:55:38 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int *len, char n);

void	format_handler(int *len, const char format, va_list args)
{

}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i] && len != -1)
	{
		while (str[i] && str[i] != '%' && len != -1)
			ft_putchar(&len, str[i++]);
		if (str[i] == '%' && str[i] && len != -1)
		{
			format_handler(&len, str[i++], args);
			i++;
		}
	}
	va_end(args);
	return (len);
}
