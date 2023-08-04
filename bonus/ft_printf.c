/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:35 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/04 14:09:11 by ohadmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_valid_format(const char *str, t_argformat *total)
{
	size_t	i;
	char	*format;

	i = 0;
	format = NULL;
	while (str[i] && !format)
	{
		format = ft_strchr("cspdiuxX", str[i]);
		if (format)
			return (format);
		i++;
	}
	if (!format)
		return (NULL);
}

void	flag_checker(t_argformat *total, const char *str, char *str_end)
{
	char	*iterator;

	iterator = str;
	while (iterator < str_end)
	{
		if (*iterator = '+')
			total->sum = 1;
		if (*iterator = ' ')
			total->space = 1;
		iterator++;
	}
}

void	flag_print(t_argformat *total, char *arg)
{
	if (total->sum && ft_strchr("pdiuxX", *arg))
	{
		if (total->sign > 0)
			ft_printc(total, '+');
		if (total->sign < 0)
			ft_printc(total, '-');
	}
	if (!total->sum && total->space && ft_strchr("pdiuxX", *arg))
	{
		if (total->sign > 0)
			ft_printc(total, ' ');
		if (total->sign < 0)
			ft_printc(total, '-');
	}
}

int	flag_parser(const char *str, t_argformat *total, va_list args)
{
	size_t	i;
	char	*str_end;

	i = 0;
	str_end = check_valid_format(str, total);
	if (str_end == (char *) str)
		return (0);
	if (!str_end)
		return (total->count = -1);
	if (format_handler(total, *str_end, args) == -1)
		return (total->count = -1);
	flag_checker(total, str, str_end);
	flag_print(total);
	return (total->s_len);
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
			ft_printc(&total.count, str[i++]);
		if (str[i] == '%' && str[i++] && total.count != -1)
		{
			// parser of flags
			total.s_len = flag_parser(str + i, &total, args);
			// format_handler with flags
			if (total.count != -1)
			{
				format_handler(&total, str[i + total.s_len], args);
				i++;
			}
		}
	}
	va_end(args);
	return (total.count);
}
