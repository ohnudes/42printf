/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:01:50 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/18 20:36:50 by ohadmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	main_spec(void);
void	sum_test(void);
void	pad_test(void)

int	main(void)
{
	// tests
	//main_spec();
	sum_test();
	pad_test();
	return (0);
}

void	pad_test(void)
{
	// c s p d i u x X %
	int	a;

	a = 0;
	printf("char = %c, str = %s, ptr = %p\n", 'a', "a", &a);
	printf("int = %d, int = %i, unsigned int = %u\n", 42, 42, 42);
	printf("hex =  %x, HEX = %X, %%\n", 42, 42);

	printf(">>PAD_TEST<<\n\n", 42);
	printf();
	printf();

}


// comparing my printf results with original printf
void	sum_test(void)
{
	int	result;

	result = 0;
	printf("\n>>SPEC_TEST<<\n\n");

	ft_printf("\n>> %%+d <<\n");

	result = ft_printf("%+d, %+d\n", 42, -42);
	ft_printf("ft_printf result = %d\n", result - 3);
	result = printf("%+d, %+d\n", 42, -42);
	ft_printf("printf result = %d\n", result - 3);
	
	ft_printf("\n>> %% i <<\n");

	result = ft_printf("% i, % i\n", 42, -42);
	ft_printf("ft_printf result = %d\n", result - 1);
	result = printf("% i, % i\n", 42, -42);
	ft_printf("printf result = %d\n", result - 1);
}

void	main_spec(void)
{
	int	result;
	int	*a;

	result = 0;
	a = NULL;
	printf("\n>>SPEC_TEST<<\n\n");

	ft_printf("\n>> %%d <<\n");

	result = ft_printf("%d", 42);
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%d", 42);
	printf("\nprintf result = %d\n", result);
	
	ft_printf("\n>> %%i <<\n");

	result = ft_printf("%i", -42);
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%i", -42);
	printf("\nprintf result = %d\n", result);

	ft_printf("\n>> %%p <<\n");

	result = ft_printf("%p", a);
	ft_printf(" ft_printf result = %d\n", result);
	result = printf("%p", a);
	ft_printf(" printf result = %d\n", result);

	ft_printf("\n>> %%c <<\n");

	result = ft_printf("%c", '@');
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%c", '@');
	printf("\nprintf result = %d\n", result);
	
	ft_printf("\n\n");

	result = ft_printf("%s", "Ayyy lmaooOOo");
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%s", "Ayyy lmaooOOo");
	printf("\nprintf result = %d\n", result);

	ft_printf("\n\n");

	result = ft_printf("%u", 2147483647);
	ft_printf("\nft_printf result = %d\n", result);
	result = printf("%u", 2147483647);
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
}
