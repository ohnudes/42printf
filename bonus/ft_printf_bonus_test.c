/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:01:50 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/14 10:04:15 by ohadmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	main_spec(int result);
//void	sum_test(int result);

int	main(void)
{
	int	result;

	result = 0;

	// tests
	main_spec(result);
	//sum_test(result);
	return (0);
}

// comparing my printf results with original printf
void	main_spec(int result)
{
	printf("\n>>SPEC_TEST<<\n\n");

	result = ft_printf("%d", 42);
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%d", 42);
	printf("\nprintf result = %d\n", result);
	
	ft_printf("\n\n");
	result = ft_printf("%i", -42);
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%i", -42);
	printf("\nprintf result = %d\n", result);

	ft_printf("\n\n");

	int	a;
	result = ft_printf("%p", &a);
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%p", &a);
	ft_printf("\nprintf result = %d\n", result);

	ft_printf("\n\n");

	result = ft_printf("%c", '@');
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%c", '@');
	printf("\nprintf result = %d\n", result);
	
	ft_printf("\n\n");

	/*
	result = ft_printf("%s", "Ayyy lmaooOOo");
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%s", "Ayyy lmaooOOo");
	printf("\nprintf result = %d\n", result);

	ft_printf("\n\n");

	result = ft_printf("%u", INT_MAX);
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%u", INT_MAX);
	ft_printf("\nprintf result = %d\n", result);

	ft_printf("\n\n");

	result = ft_printf("%x", 123456);
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%x", 123456);
	ft_printf("\nprintf result = %d\n", result);

	ft_printf("\n\n");

	result = ft_printf("%X", 123456);
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%X", 123456);
	ft_printf("\nprintf result = %d\n", result);
	ft_printf("\n\n");
	*/
}
