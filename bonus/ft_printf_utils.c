/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:31:07 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/29 20:24:27 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width_adjust(int	*flag, int *length, int size, char *str)
{
	int	iterator;

	iterator = 1;
	*flag = iterator;
	if (size != 0 && str == NULL)
		*length += size;
	else if (size == 0 && str != NULL)
	{
		if (ft_isnum(*(str + 1)))
			iterator += ft_param_len(length, str + 1);
		else
			*flag = 0;
	}
	return (iterator);
}

int	ft_param_len(int *parameter, char *str)
{
	int	digits;

	digits = 0;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		*parameter = *parameter * 10 + (*str - '0');
		digits++;
		str++;
	}
	return (digits);
}

int	ft_isnum(char n)
{
	if ((n > '0') && (n <= '9'))
		return (1);
	return (0);
}

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

void	ft_printx(t_argformat *total, char type, unsigned int data)
{
	if (total->hash == 1 && !total->flags)
		ft_hashflag(total, type);
	if (type == 'X')
		ft_printx_uc(total, data);
	else if (type == 'x')
		ft_printx_lc(total, data);
}
