/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:43:59 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/12 19:55:21 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	n_cpy;
	int	digits;

	digits = 1;
	n_cpy = n;
	while (n_cpy / 10)
	{
		n_cpy = n_cpy / 10;
		digits++;
	}
	return (digits);
}

static char	*do_itoa(char *dst, int digits, int n)
{
	int		digits_cpy;
	int		n_cpy;

	digits_cpy = digits;
	n_cpy = n;
	dst[digits_cpy] = '\0';
	while (digits_cpy > 0)
	{
		dst[digits_cpy - 1] = n_cpy % 10 + '0';
		n_cpy = n_cpy / 10;
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
