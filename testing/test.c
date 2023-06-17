/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:15:44 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/17 22:41:06 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/*
////// cases for printf ////

### format_handler
1. % followed by nothing
	Solved: doesn't print.
2. % followed by non valid character
3. 
*/

int	main(void)
{
	printf ("Case 1 == %%\n");
	int	res = printf ("%");
	printf ("\n");
	printf ("RES case 1 %d\n", res);

	printf ("////////////////\n");

	printf ("Case 2 == %%z\n");
	int	res2 = printf ("%z", 1);
	printf ("\n");
	printf ("RES case 2 %d\n", res2);

	return (0);
}
