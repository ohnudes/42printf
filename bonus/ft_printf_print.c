#include "ft_printf.h"

void	ft_printprefix(t_argformat *total)
{
	char	chr;

	chr = '0'; 
	if (!total->dash && !total->zero && total->width)
		chr = ' ';
	while (total->width - total->precission - total ->s_len > 0 \
			&& total->count != -1)
	{
		ft_printc(total, chr);
		total->width--;
	}
	while (total->precission - total->s_len && !total->truncate \
			&& total->count != -1)
	{
		ft_printc(total, chr);
		total->precission--;
	}
}

void	ft_printc(t_argformat *total, char n)
{
	int	wrbytes;

	if (total->count == -1)
		return ;
	if (total->flags)
	{
		total->s_len += 1;	
		return ;
	}
	wrbytes = 0;
	wrbytes = write(1, &n, 1);
	if (wrbytes == -1)
	{
		total->count = -1;
		return ;
	}
	else if (wrbytes == 1)
		total->count += 1;
}

void	ft_prints(t_argformat *total, char *s)
{
	size_t	i;

	if (!s || s == NULL)
	{
		ft_prints(total, "(null)");
		return ;
	}
	i = 0;
	if (total->truncate)
	{
		while (s[i] && total->truncate && total->count != -1)
		{
			ft_printc(total, s[i]);
			i++;
			total->truncate--;
		}
	}
	else		
		while (s[i] && total->count != -1)
		{
			ft_printc(total, s[i]);
			i++;
		}
}

void	ft_printsuffix(t_argformat *total)
{
	while (total->rwidth - total->count && total->count != -1)
	{
		ft_printc(total, ' ');
		total->rwidth--;
	}
}
