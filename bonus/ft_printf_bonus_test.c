/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:01:50 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/29 14:13:43 by nmaturan         ###   ########.fr       */
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
	//main_spec(); // test ok
	//sum_test(); // test ok
	//hash_test(); // test ok
	pad_test();

	return (0);
}


/* PAD_TEST NOTES:

 * the following invalidates the '0'

   result = printf("|%-010d|\n", 42);
   printf("%%-010 result = %d\n\n", result - 3);

   */
void	pad_test(void)
{
	int result;

	result = 0;
	ft_printf("\n>>PAD_TEST<<\n");
	ft_printf("'-' to all\n");
	ft_printf("'0', '.' to -diuxX-\n\n");

	ft_printf(">>PRINTF_TESTING<<\n");

	result = printf("|%+-10d|\n", 42);
	printf("1. %%+-10 result = %d\n\n", result - 3);
	// output: |+42       |

	result = printf("|%-10d|\n", 42);
	printf("2. %%-10 result = %d\n\n", result - 3);
	// output: |42        |

	ft_printf(">>FT_TESTING<<\n");

	result = ft_printf("|%+-10d|\n", 42);
	ft_printf("1. %%+-10 result = %d\n\n", result - 3);
	// output: |+42       |

	result = ft_printf("|%-10d|\n", 42);
	ft_printf("2. %%-10 result = %d\n\n", result - 3);
	// output: |42        |

	/*
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
	*/
}

/*
   result = printf("|%010.5d|\n", 42);
   printf("11. %%010.5 result = %d\n\n", result - 3);
// output: 0 is invalid when . 

result = printf("|%05.10d|\n", 42);
printf("12. %%05.10 result = %d\n\n", result - 3);
// output: 0 is invalid when . 
*/

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

// comparing my printf results with original printf
void	sum_test(void)
{
	int	result;

	result = 0;
	printf("\n>>SUM_TEST<<\n\n");

	ft_printf("\n>> %%+d <<\n");

	result = ft_printf("%+d, %+d\n", 42, -42);
	ft_printf("ft_printf result = %d\n", result - 3);
	result = printf("%+d, %+d\n", 42, -42);
	ft_printf("printf result = %d\n", result - 3);
	
	ft_printf("\n>> %% i <<\n");

	result = ft_printf("% i, % i\n", 42, -42);
	ft_printf("ft_printf result = %d\n", result - 3);
	result = printf("% i, % i\n", 42, -42);
	ft_printf("printf result = %d\n", result - 3);
}

void	main_spec(void)
{
	int	result;
	int	*a;

	result = 0;
	a = NULL;
	printf("\n>>SPEC_TEST<<\n\n");

	ft_printf("\n>> %%d <<\n");

	result = ft_printf("%d\n", 42);
	ft_printf("ft_printf result = %d\n", result - 1);
	result = printf("%d\n", 42);
	printf("printf result = %d\n", result - 1);
	
	ft_printf("\n>> %%i <<\n");

	result = ft_printf("%i\n", -42);
	ft_printf("ft_printf result = %d\n", result - 1);
	result = printf("%i\n", -42);
	printf("printf result = %d\n", result - 1);

	ft_printf("\n>> %%p <<\n");

	result = ft_printf("%p\n", a);
	ft_printf("ft_printf result = %d\n", result - 1);
	result = printf("%p\n", a);
	ft_printf("printf result = %d\n", result - 1);

	ft_printf("\n>> %%c <<\n");

	result = ft_printf("%c\n", '@');
	ft_printf("ft_printf result = %d\n", result - 1);
	result = printf("%c\n", '@');
	printf("printf result = %d\n", result - 1);
	
	ft_printf("\n\n");

	result = ft_printf("%s\n", "Ayyy lmaooOOo");
	ft_printf("ft_printf result = %d\n", result - 1);
	result = printf("%s\n", "Ayyy lmaooOOo");
	printf("printf result = %d\n", result - 1);

	ft_printf("\n\n");

	result = ft_printf("%u\n", 2147483647);
	ft_printf("ft_printf result = %d\n", result - 1);
	result = printf("%u\n", 2147483647);
	ft_printf("printf result = %d\n", result - 1);

	ft_printf("\n\n");

	result = ft_printf("%x\n", 123456);
	ft_printf("ft_printf result = %d\n", result - 1);
	result = printf("%x\n", 123456);
	ft_printf("printf result = %d\n", result - 1);

	ft_printf("\n\n");

	result = ft_printf("%X\n", 123456);
	ft_printf("ft_printf result = %d\n", result - 1);
	result = printf("%X\n", 123456);
	ft_printf("printf result = %d\n", result - 1);
	ft_printf("\n\n");
}
