/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:21:37 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/18 20:02:15 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(t_lc *total, int c)
{
	int	rvalue;

	rvalue = write(1, &c, 1);
	if (rvalue == -1)
	{
		total->check = -1;
		total->len = -1;
	}
	else
		total->len += 1;
}

void	ft_putstr(t_lc *total, char	*s)
{
	int	i;

	if (!s || s == NULL)
	{
		ft_putstr(&*total, "(null)");
		return ;
	}
	i = 0;
	while (s[i] != '\0' && total->check != -1)
	{
		ft_putchar(&*total, s[i]);
		i++;
	}
}
