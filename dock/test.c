#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	result;

	result = 0;
	result = ft_printf("%d", 123456789);
	ft_printf("\nresult = %d", result);
	printf("\nresult = %d\n", result);
	return (0);
}
