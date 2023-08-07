/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:01:50 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/07 20:04:44 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	main_spec(int result);

int	main(void)
{
	int	result;

	result = 0;
	main_spec(result);

	return (0);
}

void	main_spec(int result)
{
	result = ft_printf("%d", 42);
	ft_printf("\nresult = %d\n", result);
	result = printf("%d", 42);
	printf("\nresult = %d\n", result);

	result = ft_printf("%i", -42);
	ft_printf("\nresult = %d\n", result);
	result = printf("%i", -42);
	printf("\nresult = %d\n", result);

	result = ft_printf("%p", &result);
	ft_printf("\nresult = %d\n", result);
	result = ft_printf("%p", &result);
	ft_printf("\nresult = %d\n", result);

	result = ft_printf("%c", '@');
	ft_printf("\nresult = %d\n", result);
	result = printf("%c", '@');
	printf("\nresult = %d\n", result);

	result = ft_printf("%s", "Ayyy lmaooOOo");
	ft_printf("\nresult = %d\n", result);
	result = printf("%s", "Ayyy lmaooOOo");
	printf("\nresult = %d\n", result);

	result = ft_printf("%u", INT_MAX);
	ft_printf("\nresult = %d\n", result);
	result = ft_printf("%u", INT_MAX);
	ft_printf("\nresult = %d\n", result);

	result = ft_printf("%x", 123456);
	ft_printf("\nresult = %d\n", result);
	result = ft_printf("%x", 123456);
	ft_printf("\nresult = %d\n", result);

	result = ft_printf("%X", &result);
	ft_printf("\nresult = %d\n", result);
	result = ft_printf("%X", &result);
	ft_printf("\nresult = %d\n", result);
}
