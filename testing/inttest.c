/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:47:58 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/17 19:29:26 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct	s_lc
{
	int			len;
	int			check;
}				t_lc;

/*
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

int	ft_putint(t_lc *total, int i)
{
	int	len;

	len = 0;
	if (i == -2147483648)
	{
		len = write(1, "-2147483648", 11);
		if (len == -1)
			return (-1);
		else
			return (len);
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
	return (len);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_lc total;
	int	res;
	int res2;

	total.len = 0;
	total.check = 0;
	res = ft_putint(&total, 123456789);	

}*/

#include <stdio.h>

int	main()
{
	int	res = printf("%s\n", NULL);
	printf("res = %d\n", res);
}
