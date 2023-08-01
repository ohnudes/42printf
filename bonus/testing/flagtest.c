/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:27:24 by nmaturan          #+#    #+#             */
/*   Updated: 2023/07/31 20:47:43 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* conclusion

   FORMAT

	%[+ -0#][num].[num]specifier
	 |FLAGS|WIDTH|.|PRECISION|SPECIFIER

	 + > ' '
	 - > 0 > el numero por si solo
	 PRECISION > WIDTH
	
	 WIDTH
	 si positivo: compensa para cuota indicada por num, antes del specifier
	 si negativo: compensa para cuota indicada por num, DESPUES del specifier

	 PRECISION 

	para '-', #
		"left justify"
	agrega cantidad de espacios para llegar a la cuota declarada despues (#),
	el resultado del flag %s sumado al -# sera # + el resto de lo printeado
	como *s de printf.

	para '0', #
		"left pad with 0s"
	agrega la cantidad de 0 previos al numero final para llegar a la 
	cuota declarada (#), el resultado del flag %d sumado a 0# será # + resto 
	printeado como *s de printf, salvo que # sea menor que el contenido del 
	resultado.

	para '.', #
		"precision specifier"
	trunca o extiende con 0s para llegar a la cuota indicada por #. Resultado 
	de flag %d, f, u otro, sera .# + resto de printeado como *s de printf.

	para '#', x/X/O
	caso 1:
		"type converter"
	transforma resultado en tipo especificado post #: x para hex, X para HEX y
	O para octal.
	caso 2:, %#f
		"force decimal"
	fuerza al resultado una especificación decimal

	para "+", para %d
		"natural sign"
	especifica el signo natural del resultado: positivo o negativo.

	para ' ', para %d
		"natural sign, 2"
	especifica el signo en caso de ser negativo.
*/

#include <limits.h>

int	main(void)
{
	int	result;

	result = printf("|%+#10.4x|\n", 42);
	printf("result = %d\n", result);
	return (0);
}

/*
int	main(void)
{
	int	result;

	result = 0;
	// -#s, for %all
	printf("/// PRINTF TEST >> FLAG '-' ///\n");
	result = printf("pre string, string(-30) = |%-30s|", "hello world");
	printf("\nresult = %d\n", result);
	printf("string(-1) = "); 
	result = printf("%-1s", "hello world");
	printf(", result = %d\n", result);

	// 0, for %d, i, u, x
	printf("\n/// PRINTF TEST >> FLAG '0'///\n");
	result = printf("pre string, string(010) = %010d", 10);
	printf("\nresult = %d\n", result);
	printf("string(01) = ");
	result = printf("%01d", 10);
	printf(", result = %d\n", result);

	// el '-' tiene prioridad sobre el '0''

	// ., for precision in %d, %f
	printf("\n/// PRINTF TEST >> FLAG '.'///\n");
	int	a = 6789;
	printf("for original variable = %x:\n", a);
	result = printf("%.8x", a);
	printf("\nresult = %d\n", result);

	// POST '.'
	// con %s trunca
	// con %d / %x extiende con 0s delate, salvo que el numero indicado sea menor que
	// el total

	// #,
	printf("\n/// PRINTF TEST >> FLAG '#'///\n");
	printf("variable without flag = %x\n", 42);
	result = printf("%#x", 42);
	double	decimal = 3.141592653689793;
	printf("\nvariable without flag = %f\n", decimal);
	result = printf("%#f", decimal);
	printf("\nresult = %d\n", result);

	// ' ', 
	printf("\n/// PRINTF TEST >> FLAG ' '///\n");
	printf("original variable = %d\n", 42);
	result = printf("% d", 42);
	printf("\nresult = %d\n", result);

	// +, natural sign
	printf("\n/// PRINTF TEST >> FLAG '+'///\n");
	printf("original variable = %d\n", 42);
	result = printf("%+d", 42);
	printf("\nresult = %d\n", result);

	// '0' tiene prioridad sobre ' '

	// NEW TESTS
	printf("\n/// PRINTF TEST >> WIDTH / PREC ///\n");
	result = printf("|%7.5d|", 42);
	printf("\nresult = %d\n", result);
	result = printf("|%+-507#12.1d|", 42);
	printf("\nresult = %d\n", result);

	return (0);
}
*/
