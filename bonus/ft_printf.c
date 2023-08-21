/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:35 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/21 21:23:32 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_valid_format(const char *str, int *flags)
{
	size_t	i;

	i = 0;
	while (str[i] && !ft_strchr("cspdiuxX%\0", str[i]))
		i++;
	if (!ft_strchr("cspdiuxX%\0", str[i]))
		return (NULL);
	if (i != 0)
		*flags = 1;
	return ((char *)str + i);
}

void	flag_parser(t_argformat *total, va_list args, char *str, char *set)
{
	size_t	i;
	int		err_flag;

	i = 0;
	err_flag = 0;
	if (format_handler(total, args, *set) == -1)
		return ;
	total->flags = 0;
	while (str[i] && str + i < set && !err_flag)
	{
		if (str[i] == '+')	
			i += ft_width_adjust(&total->sum, &total->s_len, 1, NULL);
		else if (str[i] == ' ')
			i += ft_width_adjust(&total->space, &total->s_len, 1, NULL);
		else if (str[i] == '#')	
			i += ft_width_adjust(&total->hash, &total->s_len, 2, NULL);
		else if (str[i] == '-')
			i += ft_width_adjust(&total->dash, &total->width, 0, str + i);
		else if (str[i] == '0')	
			i += ft_width_adjust(&total->zero, &total->width, 0, str + i);
		else if (str[i] == '.')	
			i += ft_width_adjust(&total->dot, &total->precission, 0, str + i);
		else if (str[i] > '0' && str[i] <= '9')
			i += ft_param_len(&total->width, str + i);
		else
			err_flag++;
	}
}

int	format_handler(t_argformat *total, va_list args, const char format)
{
	//ft_printpad(total, format);
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
	//ft_printpad(total, format);
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
		if (str[i] == '%')
		{
			total.spec = check_valid_format(&str[i + 1], &total.flags);
			if (total.spec != &str[i + 1] && total.count != -1)
				flag_parser(&total, args_copy, (char *)str + i, total.spec);
			if (total.spec && total.count != -1)
				if (format_handler(&total, args, *total.spec) != -1)
					i += 1 + (total.spec - (str + i));
		}
	}
	va_end(args);
	va_end(args_copy);
	return (total.count);
}
