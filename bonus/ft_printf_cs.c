#include "ft_printf.h"

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
	while (s[i] && total->count != -1)
	{
		ft_printc(total, s[i]);
		i++;
	}
}
