/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:31:07 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/04 19:54:07 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int set)
{
	char	*occurence;

	if (!str)
		return (NULL);
	occurence = (char *) str;
	while (occurence && *occurence != set)
		occurence++;
	return (occurence);
}
