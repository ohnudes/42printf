/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:31:07 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/21 21:22:36 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void	ft_printpadding(t_argformat *total, const char format)
{


}*/

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

int	ft_width_adjust(int	*flag, int *length, int size, char *str)
{
	int	iterator;

	iterator = 1;
	*flag = iterator;
	if (size != 0 && str == NULL)
		*length += size;
	else if (size == 0 && str != NULL)
	{
		if (*(str + 1) > '0' && *(str + 1) <= '9')
			iterator = ft_param_len(length, str + 1);
		else
			*flag = 0;
	}
	return (iterator);
}

int	ft_param_len(int *parameter, char *str)
{
	int digits;

	digits = 0;
	while ((*str >= '0' && *str <= '9') && digits < 10)
	{
		*parameter = *parameter * 10 + (*str - '0');
		digits++;
		str++;
	}
	if ((*str >= '0' && *str <= '9') && digits == 10)
		return (0);
	return (digits);
}
