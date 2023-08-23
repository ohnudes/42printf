/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:35 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/23 12:32:26 by ohadmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// looks for specifier as %d, %c, etc... and then calculates the argument lenght
char	*check_valid_format(t_argformat *total, va_list args, const char *str)
{
	char	*ref;
	int		arg_len;
	size_t	i;

	i = 0;
	arg_len = 0;
	ref = NULL;
	if (*str)
		ref = (char*) str;
	while (ref[i] && !ft_strchr("cspdiuxX%\0", ref[i]))
		i++;
	if (ref && !ft_strchr("cspdiuxX%\0", ref[i]))
		return (NULL);
	if (ref && i != 0)
	{
		total->flags = 1;
		arg_len = format_handler(total, args, *(ref + i));
		if (arg_len != -1)
			total->flags = 0;
	}
	return (ref + i);
}

int	flag_parser(t_argformat *total, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && str + i < total->spec && total->flags == 0)
	{
		j = 0;
		if (str[i] == '+')
			j = ft_width_adjust(&total->sum, &total->s_len, 1, NULL);
		else if (str[i] == ' ')
			j = ft_width_adjust(&total->space, &total->s_len, 1, NULL);
		else if (str[i] == '#')
			j = ft_width_adjust(&total->hash, &total->s_len, 2, NULL);
		else if (str[i] == '-')
			j = ft_width_adjust(&total->dash, &total->rwidth, 0, str + i);
		else if (str[i] == '0' && ft_strchr("diuxX", str[i]))
			j = ft_width_adjust(&total->zero, &total->width, 0, str + i);
		else if (str[i] == '.' && ft_strchr("diuxX", str[i]))
			j = ft_width_adjust(&total->dot, &total->width, 0, str + i);
		else if (ft_isnum(str[i]))
			j = ft_param_len(&total->width, str + i);
		if (j <= 7 && j > 0)
			i += j;
		else
			return (total->count = -1);
	}
	return (1);
}

int	format_handler(t_argformat *total, va_list args, const char format)
{
	ft_flagvalidation(total, format);
	ft_printprefix(total);
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
	else if ((format == 'x' || format == 'X') && total->count != -1)
		ft_printx(total, format, va_arg(args, unsigned int));
	else if (format == '%' && total->count != -1)
		ft_printc(total, '%');
	if (total->count != -1)
		ft_printsuffix(total);
	if (total->count == -1)
		return (-1);
	return (total->count);
}

int	ft_printf(const char *str, ...)
{
	t_argformat	total;
	va_list		args;
	va_list		args_copy;
	size_t		i;

	total = (t_argformat){};
	va_start(args, str);
	va_copy(args_copy, args);
	i = 0;
	while (str[i] != '\0' && total.count != -1)
	{
		while (str[i] && str[i] != '%' && total.count != -1)
			ft_printc(&total, str[i++]);
		if (str[i] == '%' && total.count != -1)
		{
			total.spec = check_valid_format(&total, args_copy, &str[i + 1]);
			if (total.spec != &str[i + 1] && total.count != -1)
				flag_parser(&total, (char *)str + i);
			if (total.spec && total.count != -1)
				if (format_handler(&total, args, *total.spec) != -1)
					i += 1 + (total.spec - (str + i));
		}
	}
	va_end(args);
	va_end(args_copy);
	return (total.count);
}
