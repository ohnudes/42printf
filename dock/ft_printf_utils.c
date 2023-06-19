/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:57:39 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/19 13:36:24 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(t_lc *total, void *p)
{
	intptr_t	cp;

	cp = (intptr_t) p;
	if (!p)
		ft_putstr(&*total, "0x0");
	else
		ft_putstr(&*total, "0x");
	if (total->check != -1)
		ft_put_l_hex(&*total, cp);
}

void	ft_putint(t_lc *total, int i)
{
	if (i == -2147483648)
	{
		ft_putstr(&*total, "-2147483648");
		return ;
	}
	if (i < 0 && total->check != -1)
	{
		ft_putchar(&*total, '-');
		i = -i;
	}
	if (i / 10 && total->check != -1)
		ft_putint(&*total, i / 10);
	ft_putchar(&*total, (i % 10) + '0');
}

void	ft_putuint(t_lc *total, unsigned int u)
{
	if (u / 10)
		ft_putuint(&*total, u / 10);
	if (total->check != -1)
		ft_putchar(&*total, (u % 10) + '0');
}

void	ft_put_l_hex(t_lc *total, unsigned int x)
{
	if (x / 16)
		ft_put_l_hex(&*total, x / 16);
	if (total->check != -1)
		ft_putchar(&*total, "0123456789abcdef"[x % 16]);
}

void	ft_put_u_hex(t_lc *total, unsigned int X)
{
	if (X / 16)
		ft_put_u_hex(&*total, X / 16);
	if (total->check != -1)
		ft_putchar(&*total, "0123456789ABCDEF"[X % 16]);
}
