/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:30:32 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/17 19:35:26 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(t_lc *total, int c)
{
	int checker;

	checker = write(1, &c, 1);
	if (checker == -1)
	{
		total->check = 1;
		return (-1);
	}
	return (checker);
}

int	ft_putstr(t_lc *total, char	*s)
{
	int	len;

	if (!s)
	{
		len = write(1, "(null)", 6);
		if (len == -1)
		{
			total->check = 1;
			return (-1);
		}
		return (6);
	}
	while (s && total->check != 1)
		len += ft_putchar(&*total, *s++);
	if (total->check == 1)
		return (-1);
	return (len);
}

void	ft_put_l_hex(t_lc *total, unsigned int x)
{
	if (x)
	{
		if (x / 16)
			ft_put_l_hex(&*total, x / 16);
		if (total->check != 1)
			total->len += ft_putchar(&*total, "0123456789abcdef"[x % 16]);
	}
	return ;
}

int		ft_putptr(t_lc *total, unsigned long p)
{
	int	len;
	
	len = 0;
	if (!p)
	{
		len = ft_putstr(&*total, "0x0");
		return (len);
	}
	else
		len = ft_putstr(&*total, "0x");
	if (total->check != 1)
		ft_put_l_hex(&*total, p);
	if (total->check == 1)
		return (-1);
	return (len);
}

int	main(void)
{
	char	*ptr;
	t_lc	total;

	total.len = 0;
	total.check = 0;
	ptr = NULL;
	// testing ptr cases differences
	// 1. ptr = ""
	// 2. negative value
	// 3. ptr = NULL / 0
	int	res2 = ft_putptr(&total, NULL);
	int	res = printf("%p\n", NULL);
	printf("%d\n", res);
	return (0);
}

// conclusions
// 1. it's a valid pointer with no content: prints 11 (+1 for \n)
// 2. the value will be implicitly casted into long int, so in case for -1
// it will give max_value
// 3. it prints 0x0 with value of 3.
