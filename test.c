/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:32:42 by nmaturan          #+#    #+#             */
/*   Updated: 2023/09/19 18:05:04 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	result;

	result = 0;
	result = ft_printf("%p\n", "");
	ft_printf("printf result = %d\n", result - 1);

	result = printf("%p\n", "");
	printf("printf result = %d\n", result - 1);
	return (0);
}
