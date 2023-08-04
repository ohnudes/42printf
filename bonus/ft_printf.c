/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:35 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/04 20:02:59 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_valid_format(const char *str, t_argformat *total)
{
	size_t	i;

	i = 0;
	while (str[i] && !ft_strchr("cspdiuxX%", str[i]))
		i++;
	if (!ft_strchr("cspdiuxX%", str[i]))
		return (NULL);
	return ((char *)str + i);
}

int	flag_parser(t_argformat *total, const char *str)
{
	size_t	i;
	char	*str_end;

	i = 0;
	str_end = check_valid_format(str, total);
	if (str_end == (char *) str)
		return (0);
	if (!str_end)
		return (total->count = -1);
	return (total->s_len);
}

int	format_handler(t_argformat *total, va_list args, const char format)
{
	if (format == 'c' && total->count != -1)
		ft_printc(total, va_arg(args, int));
	else if (format == 's' && total->count != -1)
		ft_prints(total, va_arg(args, char *));
	else if (format == 'p' && total->count != -1)
		ft_printp(total, va_arg(args, void *));
	else if ((format == 'd' || format == 'i') && total->count != -1)
		ft_printdi(total, va_arg(args, int));
	else if (format == 'u' && total->count != -1)
		ft_printu(total, va_arg(args, unsigned int));
	else if (format == 'x' && total->count != -1)
		ft_printx(total, va_arg(args, unsigned int));
	else if (format == 'X' && total->count != -1)
		ft_printX(total, va_arg(args, unsigned int));
	else if (format == '%' && total->count != -1)
		ft_printc(total, '%');
	if (total->count == -1)
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	t_argformat	total;

	va_start(args, str);
	total = (t_argformat){};
	i = 0;
	while (str[i] && str[i] != '%' && total.count != -1)
	{
		ft_printc(&total, str[i++]);
		if (str[i] == '%' && str[i++] && total.count != -1)
			total.s_len = flag_parser(&total, str + i);
		if (str[i] && total.count != -1)
			if (format_handler(&total, args, str[i + total.s_len]) == -1)
				return (-1);
		i++;
	}
	va_end(args);
	return (total.count);
}
