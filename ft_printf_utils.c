/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:45:17 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/12 13:13:20 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putptr(unsigned long c)
{
	return (1);
}

int	ft_putnbr(int c)
{
	int		str_lenght;
	char	*str;
	
	str = ft_itoa(c);
	str_lenght = ft_putstr(str);
	free (str);
	
	return (str_lenght);
}

int	ft_putunbr(unsigned int c)
{
	int		str_lenght;
	char	*str;
	
	str = ft_itoa(c);
	str_lenght = ft_putstr(str);
	free (str);

	return (1);
}

int	ft_putlhex(unsigned long c)
{
	return (1);
}

int	ft_putuhex(unsigned long c)
{
	return (1);
}

