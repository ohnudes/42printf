/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:49:07 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/17 22:57:52 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

typedef struct s_lc
{
	int			len;
	int			check;
}				t_lc;


void	ft_putchar(t_lc *total, int c)
{
	int	rvalue;

	rvalue = write(1, &c, 1);
	if (rvalue == -1)
	{
		total->check = -1;
		total->len = -1;
	}
	else
		total->len++;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_lc	total;
	int		ref;

	total.len = 0;
	total.check = 0;
	va_start(args, str);
	while (str[total.check] && total.check != -1)
		ft_putchar(&total, *str);
	if (total.check == -1)
		return (-1);
	return (total.len);
}

int	main(void)
{
	int res = ft_printf("alo");
	//ft_printf("", res);
}

/*
int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_lc	total;
	int		ref;

	total.len = 0;
	total.check = 0;
	va_start(args, str);
//	ref = ft_strchr(&total, str, '%');
	while (str[total.check] && total.check != -1)
	{
		ft_putchar(&total, *str);
		//while (str[total.len] && total.len < ref && total.check != -1)
//		if (total.len == ref && total.check != -1)
//		{
//			format_handler(&total, args, str[total.len + 1]);
//			if (str[total.len])
//				ref = ft_strchr(&total, (str + total.len), '%');
//		}
	}
	if (total.check == -1)
		return (-1);
	return (total.len);
}
*/
