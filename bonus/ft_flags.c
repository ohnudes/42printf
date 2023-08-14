/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:42:27 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/14 20:54:26 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sumflag(t_argformat *total)
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
}
