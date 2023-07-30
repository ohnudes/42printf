/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:27:24 by nmaturan          #+#    #+#             */
/*   Updated: 2023/07/30 18:37:23 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* conclusion

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

int	main(void)
{
	int	result;

	result = 0;
	// -#s, for %all
	printf("/// PRINTF TEST >> FLAG '-' ///\n");
	result = printf("pre string, string(-30) = %-30s", "hello world");
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

	// ., for precision in %d, %f
	printf("\n/// PRINTF TEST >> FLAG '.'///\n");
	float	a = 1.1234567;
	printf("for original variable = %f:\n", a);
	result = printf("%.3f", a);
	printf("\nresult = %d\n", result);

	// #,
	printf("\n/// PRINTF TEST >> FLAG '#'///\n");
	printf("variable without flag = %x\n", 0x2a);
	result = printf("%#x", 0x2a);
	double	decimal = 3.141592653689793;
	printf("\nvariable without flag = %f\n", decimal);
	result = printf("%#f", decimal);
	printf("\nresult = %d\n", result);

	// ' ', 
	printf("\n/// PRINTF TEST >> FLAG ' '///\n");
	printf("original variable = %d\n", 42);
	result = printf("%+d", 42);
	printf("\nresult = %d\n", result);

	// +, natural sign
	printf("\n/// PRINTF TEST >> FLAG '+'///\n");
	printf("original variable = %d\n", 42);
	result = printf("%+d", 42);
	printf("\nresult = %d\n", result);

	return (0);
}
