/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:15:44 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/16 17:52:53 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_putchar(t_lc *total, int c)
{
	int	checker;

	checker = write(1, &c, 1);
	//total->check = 1;
	//if (total->check == 1)
	//	return (-1);
	return (checker);
}

int	ft_put_l_hex(t_lc *total, unsigned int x)
{
	int	len;

	len = 0;
	if (x / 16)
		ft_put_l_hex(&*total, x / 16);
	len += ft_putchar(&*total, "0123456789abcdef"[x % 16]);
	return (len);
}

// ver casos
// 1. devuelve buen len
// 2. checkear caso de error

int	main(void)
{
	t_lc total;
	int	res;

	total.len = 0;
	total.check = 0;
	res = ft_put_l_hex(&total, 123456789);
	printf ("\n");
	printf ("total.len = %d\n", total.len);
	printf ("res = %d\n", res);
	printf ("checker says it's... %d", total.check);
	return (0);
}
