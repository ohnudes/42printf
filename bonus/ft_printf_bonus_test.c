/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:01:50 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/23 12:33:12 by ohadmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	main_spec(void);
void	sum_test(void);
void	pad_test(void);
void	hash_test(void);

// specifiers
// c s p d i u x X %

int	main(void)
{
	// tests
	// main_spec();
	// sum_test();
	// pad_test();
	// hash_test();
	return (0);
}

void	hash_test(void)
{
	printf("\n>>HASH_TEST<<\n");
	printf("'#' to -Xx-\n\n");

	printf(">>PRINTF_TESTING<<\n");
	int result = printf("|%#x|\n", 42);
	printf("%%#x result = %d\n\n", result - 3);

	result = printf("|%#X|\n", 42);
	printf("%%#X result = %d\n\n", result - 3);

	printf(">>FT_TESTING<<\n");

	result = ft_printf("|%#x|\n", 42);
	ft_printf("%%#x result = %d\n\n", result - 3);

	result = ft_printf("|%#X|\n", 42);
	ft_printf("%%#X result = %d\n\n", result - 3);
}

/* PAD_TEST NOTES:

 * the following invalidates the '0'

   result = printf("|%-010d|\n", 42);
   printf("%%-010 result = %d\n\n", result - 3);

   */
void	pad_test(void)
{
	printf("\n>>PAD_TEST<<\n");
	printf("'-' to all\n");
	printf("'0', '.' to -diuxX-\n\n");

	printf(">>PRINTF_TESTING<<\n");

	int result = printf("|%+-10d|\n", 42);
	printf("1. %%+-10 result = %d\n\n", result - 3);
	// output: |+42       |

	result = printf("|%-10d|\n", 42);
	printf("2. %%-10 result = %d\n\n", result - 3);
	// output: |42        |

	result = printf("|%10d|\n", 42);
	printf("3. %%10 result = %d\n\n", result - 3);
	// output: |        42|

	result = printf("|%010d|\n", 42);
	printf("4. %%010 result = %d\n\n", result - 3);
	// output: |0000000042|

	result = printf("|%.10d|\n", 42);
	printf("5. %%.10 result = %d\n\n", result - 3);
	// output: |0000000042|

	result = printf("|%-10.5d|\n", 42);
	printf("6. %%-10.5 result = %d\n\n", result - 3);
	// output: |00042     |

	result = printf("|%10.5d|\n", 42);
	printf("7. %%10.5 result = %d\n\n", result - 3);
	// output: |     00042|

	result = printf("|%-5.10d|\n", 42);
	printf("8. %%-5.10 result = %d\n\n", result - 3);
	// output: |0000000042|

	result = printf("|%5.10d|\n", 42);
	printf("9. %%5.10 result = %d\n\n", result - 3);
	// output: |0000000042|

	result = printf("|%-.d|\n", 42);
	printf("10. %%-. result = %d\n\n", result - 3);
	// output: |42|

	result = printf("|%.5s|\n", "1234567890");
	printf("11. %%.5s result = %d\n\n", result - 3);
	// output: |12345|

	result = printf("|%.2s|\n", "");
	printf("11. %%.2s + NULL result = %d\n\n", result - 3);
	// output: tbd campus

	/*
	result = printf("|%010.5d|\n", 42);
	printf("11. %%010.5 result = %d\n\n", result - 3);
	// output: 0 is invalid when . 

	result = printf("|%05.10d|\n", 42);
	printf("12. %%05.10 result = %d\n\n", result - 3);
	// output: 0 is invalid when . 
*/
	printf(">>FT_TESTING<<\n");
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
