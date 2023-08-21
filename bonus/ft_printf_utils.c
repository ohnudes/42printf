/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:31:07 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/21 11:18:25 by ohadmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, char set)
{
	char	*occurence;

	if (str)
	{
		occurence = (char *) str;
		while (*occurence != '\0' && *occurence != set)
			occurence++;
		if (*occurence == set)
			return (occurence);
	}
	return (NULL);
}

int	ft_width_check(t_argformat *total, char *str)
{
	char digits;

	digits = 0;
	total->width = 0;
	while ((*str >= '0' && *str <= '9') && digits < 10)
	{
		total->width = total->width * 10 + (*str - '0');
		digits++;
		str++;
	}
	if ((*str >= '0' && *str <= '9') && digits == 10)
		return (total->count = -1);
	return (digits);
}
