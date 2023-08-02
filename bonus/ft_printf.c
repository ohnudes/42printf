/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:35 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/02 14:48:44 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// returns ptr to end of flags
char	*check_valid_format(const char *str, t_argformat *total);

int	flag_parser(const char *str, t_argformat *total)
{
	size_t	i;
	char	*str_end;

	i = 0;
	str_end = check_valid_format(str, total);
	if (!str_end || !ft_strchr("cspdiuxX%", *str_end))
		return (total->count = -1);
	while (str + i < str_end)
		i++;


}

int	format_handler(t_argformat *total, const char format, va_list args)
{
	if (format == 'c' && total->count != -1)
	{}
	else if (format == 's' && total->count != -1)
	{}
	else if (format == 'p' && total->count != -1)
	{}
	else if ((format == 'd' || format == 'i') && total->count != -1)
	{}
	else if (format == 'u' && total->count != -1)
	{}
	else if (format == 'x' && total->count != -1)
	{}
	else if (format == 'X' && total->count != -1)
	{}
	else if (format == '%' && total->count != -1)
	{}
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
	while (str[i] && total.count != -1)
	{
		while (str[i] && str[i] != '%' && total.count != -1)
			ft_putchar(&total.count, str[i++]);
		if (str[i] == '%' && str[i++] && total.count != -1)
		{
			// parser of flags
			total.s_len = flag_parser(str + i, &total);
			// format_handler with flags
			format_handler(&total, str[i + total.s_len], args);
			i++;
		}
	}
	va_end(args);
	return (total.count);
}
