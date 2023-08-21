/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:42:27 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/21 19:30:14 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hashflag(t_argformat *total, char type)
{
	if (type == 'X')
		ft_prints(total, "0X");
	else if (type == 'x')
		ft_prints(total, "0x");
	total->hash = 0;
}

void	ft_sumflag(t_argformat *total)
{
	if (total->sum)
		ft_printc(total, '+');
	else if (total->space && !total->sum)
		ft_printc(total, ' ');
	total->sum = 0;
	total->space = 0;
}
/*
void	ft_widthflag(t_argformat *total, int *width)
{
	if (total->dash)
	{
		ft_printc(total, '+');
		total->sum = 0;
		total->space = 0;
	}
	if (total->zero)
	{
		ft_printc(total, ' ');
		total->space = 0;
	}
	if (total->dot)
	{
		ft_printc(total, ' ');
		total->space = 0;
	}
}*/
