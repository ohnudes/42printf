/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcami.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:02:15 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/17 23:18:54 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_auxiliar(va_list args, char coso)
{
	if (coso == 'c')
		ft_printchr(va_arg(args, int));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);

	while (str)
	{
		if (*str == '%') 
			ft_auxiliar(va_list, str + 1);
		str++;
	}

	va_end(args);
	return (len);
}

int	main(void)
{
	return (0);
}
