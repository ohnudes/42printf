/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:45:17 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/16 16:38:11 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>
#include <unistd.h>

// %c - functional
int	ft_putchar(int c)
{
	int var;

	var = write(1, &c, 1);
	if (var == -1)
		return (-1);
	return (1);
}

// %s - functional
int	ft_putstr(char *s)
{
	int	i;
	int	check;

	i = 0;
	if (!s)
	{
		check = write(1, "(null)", 6);
		if (check == -1)
			return (check);
	}
	while (s[i])
	{
		check = write(1, &s[i], 1);
		if (check == -1)
			return (check);
		i++;
	}
	return (i + 1);
}

// %d - functional
int	ft_putnbr(int d)
{
	int		str_lenght;
	char	*s;
	
	s = ft_itoa(d);
	str_lenght = ft_putstr(s);
	if (str_lenght == -1)
	{
		if (s)
			free (s);
		return (-1);
	}
	if (s)
		free (s);

	return (str_lenght);
}

// %u - TO BE TESTED 
int	ft_putunbr(unsigned int u)
{
	int		str_lenght;
	char	*s;

	s = ft_itoa(u);
	str_lenght = ft_putstr(s);
	if (str_lenght == -1)
	{
		if (s)
			free (s);
		return (-1);
	}
	if (s)
		free (s);

	return (str_lenght);
}

// %x - functional
int	ft_puthex(unsigned int x)
{
	int	var;
	int	total;

	total = 0;
	if (x)
	{	
		var = ft_puthex(x/16);
		if (var == -1)
			return (-1);
		total += var;
		var = ft_putchar("0123456789abcdef"[x % 16]);
		if (var == -1)
			return (-1);
		total += var;
	}
	return (total);
}

// %p - functional
int	ft_putptr(unsigned long p)
{
	int	var;

	if (!p)
	{
		var = ft_putstr("0x0");
		return (var);
	}
	var = ft_putstr("0x");
	if (var == -1)
		return (-1);
	var = ft_puthex(p);
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
/*
int	ft_putptr(unsigned long c)
{
	return (1);
}
*/
