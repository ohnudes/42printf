/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:45:17 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/12 20:01:36 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(int c)
{
	int var;

	var = write(1, &c, 1);
	if (var == -1)
		return (-1);
	printf("check putchar");
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	check;

	i = 0;
	if (!str)
	{
		check = write(1, "(null)", 6);
		if (check == -1)
			return (check);
	}
	while (str[i])
	{
		check = write(1, &str[i], 1);
		if (check == -1)
			return (check);
		i++;
	}
	return (i + 1);
}

/*
int	ft_putptr(unsigned long c)
{
	return (1);
}
*/
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


int	do_hex(unsigned long num)
{
	int	var;
	int	total;

	total = 0;
	if (num)
	{	
		var = do_hex(num/16);
		if (var == -1)
			return (-1);
		total += var;
		var = ft_putchar("0123456789abcdef"[num % 16]);
		if (var == -1)
			return (-1);
		total += var;
	}
	return (total);
}

int	ft_putptr(unsigned long num)
{
	int	var;

	if (!num)
	{
		var = ft_putstr("0x0");
		return (var);
	}
	var = ft_putstr("0x");
	if (var == -1)
		return (-1);
	var = do_hex(num);
	if (var == -1)
		return (-1);
	return (var + 2);
}
/*
int	ft_putuhex(unsigned int c)
{

	return (1);
}
*/
