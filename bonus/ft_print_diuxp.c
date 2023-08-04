/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diuxp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:23:45 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/04 18:55:01 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdi(t_argformat *total, int nb)
{
	if (nb == -2147483648)
	{
		ft_prints(total,"-2147483648");
		total->sum = 0;
		total->space = 0;
	}
	if (nb < 0)
	{
		ft_printc(total, '-');
		total->sum = 0;
		total->space = 0;
		nb *= -1;
	}
	ft_printu(total, nb);
	return ;
}

void	ft_printu(t_argformat *total, unsigned int u)
{
	if (total->sum)
	{
		ft_printc(total, '+');
		total->sum = 0;
		total->space = 0;
	}
	if (total->space)
	{
		ft_printc(total, ' ');
		total->space = 0;
	}
	if (u / 10 && total->count != -1)
		ft_printu(total, u / 10);
	if (total->count != -1)
		ft_printc(total, (u % 10) + '0');
}

void	ft_printx_lc(t_argformat *total, unsigned int x)
{
	if (total->sum)
	{
		ft_printc(total, '+');
		total->sum = 0;
		total->space = 0;
	}
	if (total->space)
	{
		ft_printc(total, ' ');
		total->space = 0;
	}
	if (x / 16 && total->count != -1)
		ft_printx(total, x / 16);
	if (total->count != -1)
		ft_printc(total, "0123456789abcdef"[x % 16]);
}

void	ft_printx_uc(t_argformat *total, unsigned int x)
{
	if (total->sum)
	{
		ft_printc(total, '+');
		total->sum = 0;
		total->space = 0;
	}
	if (total->space)
	{
		ft_printc(total, ' ');
		total->space = 0;
	}
	if (x / 16 && total->count != -1)
		ft_printx(total, x / 16);
	if (total->count != -1)
		ft_printc(total, "0123456789ABCDEF"[x % 16]);
}

void ft_printp(t_argformat *total, void *ptr)
{
	intptr_t	ip;

	ip = (intptr_t) ptr;
	if (!ip)
		ft_prints(total, "0x0");
	else
	{
		ft_prints(total, "0x");
		ft_printx_lc(total, ip);
	}
}
