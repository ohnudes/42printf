/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:43:59 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/13 19:28:46 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count(int n)
{
	int	digits;

	digits = 1;
	while (n / 10)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static char	*do_itoa(char *dst, int digits, int n)
{
	int		digits_cpy;

	digits_cpy = digits;
	dst[digits_cpy] = '\0';
	while (digits_cpy > 0)
	{
		dst[digits_cpy - 1] = n % 10 + '0';
		n = n / 10;
		digits_cpy--;
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	int			digits;
	char		*res;
	long int	max_num;

	max_num = n;
	digits = digit_count(max_num);
	if (max_num < 0)
		digits++;
	res = malloc(sizeof(char) * (digits + 1));
	if (!res)
		return (NULL);
	if (max_num < 0)
	{
		res[0] = '-';
		*(res + 1) = *do_itoa(res + 1, digits - 1, - max_num);
	}
	else
		res = do_itoa(res, digits, max_num);
	return (res);
}
