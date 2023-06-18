
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct	s_lc
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
		total->len += 1;
}

void	ft_putstr(t_lc *total, char	*s)
{
	int	i;

	i = 0;
	if (!s)
		ft_putstr(&*total, "(null)");
	while (s[i] && total->check != -1)
	{
		ft_putchar(&*total, s[i]);
		i++;
	}
}

int	format_handler(t_lc *total, va_list args, const char format)
{
	if (format == 'c' && total->check != -1)
		ft_putchar(&*total, va_arg(args, int));
	else if (format == 's' && total->check != -1)
		ft_putstr(&*total, va_arg(args, char *));
	else if (format == '%' && total->check != -1)
		ft_putchar(&*total, '%');
	else
		total->check = -1;
	return (total->check);
}


// casos
// 1. strchr finds %
// 2. strchr finds no %
// 3. strchr finds % after first %
// 4. strchr finds no % after first %

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_lc	total;
	int		i;

	total.len = 0;
	total.check = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0' && total.check != -1)
	{
		while (str[i] && str[i] != '%' && total.check != -1)
			ft_putchar(&total, str[i++]);
		if (str[i] == '%' && str[i] && total.check != -1)
		{
			if (!format_handler(&total, args, str[++i]))
				i++;
		}
	}
	if (total.check == -1)
		return (-1);
	return (total.len);
}

int	main()
{
	printf("/// FT_PRINTF ///\n");
	int	res = ft_printf("abc %s def", "123");
	printf("\n");
	printf("/// OS_PRINTF ///\n");
	int res2 = printf("abc %s def", "123");
	printf("\n");

	printf("ft_printf returns = %d\n", res);
	printf("OS_printf returns = %d\n", res2);
	
	return (0);
}
