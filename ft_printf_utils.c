/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:57:39 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/16 18:14:44 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(t_lc *total, int c)
{
	int	len;

	len = write(1, &c, 1);
	if (len == -1)
	{
		total->check = 1;
		return (-1);
	}
	return (len);
}

// casos:
// 1. ok str - ok
// 2. str null - ok: devuelve int printf 0
// 3. !str - no args? 
// 4. %s c/ int - segfault - segfault
int		ft_putstr(t_lc *total, char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (0);
	}
	while (s && total->check != 1)
	{
		if (!write(1, &s, 1))
		{
			total->check = 1;
			return (-1);
		}
		s++;
		len++;
	}
	return (len);
}

int		ft_putptr(t_lc *total, unsigned long p)
{
	int len;

	len = 0;
	if (!p)
		len = ft_putstr(&*total, "0x0");
	else
		len = ft_putstr(&*total, "0x");
	return (len);
}

void	ft_putint(t_lc *total, int i)
{
	int	len;

	len = 0;
	if (i == -2147483648)
	{
		len = write(1, "-2147483648", 11);
		if (len == -1)
			return ;
	}
 	if (i < 0 && total->check != 1)
	{
		ft_putchar(&*total, '-');
		i = -i;
	}
	if (i / 10 && total->check != 1)
		ft_putint(&*total, i/10);
	ft_putchar(&*total, i % 10);
	len++;
	return ;
}

void		ft_putuint(t_lc *total, unsigned int u)
{
	int	len;

	len += 0;
	if (u / 10)
		ft_putuint(&*total, u / 10);
	if (total->check == 1)
		return ;
	total->len += ft_putchar(&*total, u % 10);
	return ;
}

void	ft_put_l_hex(t_lc *total, unsigned int x)
{
	int len;

	len += 0; // check case if this works for uninitialised len
	if (x / 16)
		ft_put_l_hex(&*total, x/16);
	if (total->check != 1)
		len += ft_putchar(&*total, "0123456789abcdef"[x % 16]) ;
	return ;
}

void	ft_put_u_hex(t_lc *total, unsigned int X)
{
	int len;

	len = 0;
	if (X / 16)
		ft_put_l_hex(&*total, X / 16);
	if (total->check != 1)
		len += ft_putchar(&*total, "0123456789ABCDEF"[X % 16]) ;
	return ;
}
