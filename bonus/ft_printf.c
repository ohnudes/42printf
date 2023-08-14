/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:35 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/14 21:49:14 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_sum_space(const char *str, t_argformat *total)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
			total->sum += 1;
		if (str[i] == ' ')
			total->space += 1;
		i++;
	}
}

char	*check_valid_format(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && !ft_strchr("cspdiuxX%", str[i]))
		i++;
	if (!ft_strchr("cspdiuxX%", str[i]))
		return (NULL);
	return ((char *)str + i);
}

void	flag_parser(t_argformat *total, va_list args, char *str, char *set)
{
	size_t	i;

	i = 0;
	total->s_len = format_handler(total, args, *set);
	while (str[i] && str + i < set)
	{
		if (str[i] == '+')	
			total->sum = 1;
		else if (str[i] == ' ')	
			total->space = 1;
		else if (str[i] == '-')	
			total->dash = 1;
		else if (str[i] == '0')	
			total->zero = 1;
		else if (str[i] == '#')	
			total->hash = 1;
		else if (str[i] == '.')	
			total->precision = 1;
		i++;
	}
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
		ft_printx_lc(total, va_arg(args, unsigned int));
	else if (format == 'X' && total->count != -1)
		ft_printx_uc(total, va_arg(args, unsigned int));
	else if (format == '%' && total->count != -1)
		ft_printc(total, '%');
	if (total->count == -1)
		return (-1);
	return (total->count);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	char		*spec;
	size_t		i;
	t_argformat	total;

	va_start(args, str);
	total = (t_argformat){};
	spec = NULL;
	i = 0;
	while (str[i] != '\0' && total.count != -1)
	{
		while (str[i] && str[i] != '%' && total.count != -1)
			ft_printc(&total, str[i++]);
		if (str[i] == '%')
		{
			spec = check_valid_format(&str[i + 1]);
			if (spec != &str[i + 1] && total.count != -1)
				flag_parser(&total, args, (char *)str + i, spec);
			if (spec && total.count != -1)
				if (format_handler(&total, args, *spec) != -1)
					i += (spec - (str + i));
		}
	}
	va_end(args);
	return (total.count);
}
