/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:19:47 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/14 20:09:19 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "42libft/libft.h"
#include <stdarg.h>

int	format_handler(va_list args, const char format)
{
	if (format == 'c')


	return (total);
}

int	ft_printf(const char *str, ...) 
{
	va_list args;
	size_t	i;
	char	*iter;
	int		strlen;
	int		refchk;

	// objectives
	// 1. return (string lenght + format_len value)
	// 2. look for '%'s and multiple signs

	va_start(args, str);
	refchk = ft_strchr(str, '%');
	
		// strlen  
	if (!(ft_strchr(str + i, '%')))
		strlen = ft_printstr(str);
	else 
	{
		
	
		ft_s
	}
	while (str[i])
	{
		if (!(ft_strchr(str + i, '%')))
			strlen = ft_printstr(str+i);
		if (refchk)
		{
			ft_substr(const char *s, unsigned int start, size_t len)
		}
	}


	va_end(args);
	return (strlen);
}

{
	{
		// %cspdiuxX%
		if (*str == '%')
		{
			format_len = format_handler(args, (*str + 1));
			str++;
		}
		if (format_len == -1)
			return (-1);
		strlen += format_len;
		str++;
	}
	va_end(args);


	return (strlen);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	res = ft_printf("", argv[1]);
	int res2 = printf("", argv[1]);

	printf("ft_printf returns = %d\n", res);
	printf("OS_printf returns = %d\n", res);
	
	return (0);
}
