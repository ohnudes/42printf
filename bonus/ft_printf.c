/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:35 by nmaturan          #+#    #+#             */
/*   Updated: 2023/07/31 20:46:23 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct	s_argformat
{
	int	count;
	int	s_len;
	int	sum;
	int	space;
	int	dash;
	int	zero;
	int	hash;
	int	width;
	int	precision;
}		t_argformat;

char	*ft_strchr(char *str, char set);

void	ft_putchar(int *count, char n)
{
	int	wrbytes;

	if (*count == -1)
		return ;
	wrbytes = 0;
	wrbytes = write(1, &n, 1);
	if (wrbytes == -1)
	{
		*count = -1;
		return ;
	}
	else if (wrbytes == 1)
		*count += 1;
}

int	flag_parser(const char *str, t_argformat *total)
{
	size_t	i;
	char	*specifier;

	i = 0;
	specifier = NULL;
	while (str[i] && !specifier)
	{
		specifier = ft_strchr("cspdiuxX%", str[i]);
		i++;
	}
	if (!specifier)
		return (total->count = -1);

	
	
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
