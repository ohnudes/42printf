
#include <unistd.h>

typedef struct	s_lc
{
	int			len;
	int			check;
}				t_lc;
/*
int len_gestor(t_lc *total, int	rvalue)
{
	if (rvalue == -1)
	{
		total->check = -1;
		total->len = -1;
		return (-1);
	}
	else
		total->len = total->len + rvalue;
	return (0);
}*/

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
		total->len += rvalue;
}

void	ft_putstr(t_lc *total, char	*s)
{
	int	i;
	i = 0;

	if (!s)
		ft_putstr(&*total, "(null)");
	while (s[i] != '\0' && total->check != -1)
		ft_putchar(&*total, s[i++]);
}

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	t_lc total;

	total.len = 0;
	total.check = 0;

	printf("total.len pre str == %d\n", total.len);
	if (argc > 1)
		ft_putstr(&total, argv[1]);
	else
		ft_putstr(&total, "(null)");
	if (total.check == -1)
		return (-1);
	printf("\n");
	printf("total.len == %d\n", total.len);
	printf("/// printf version ///\n");
	int res = printf("string = %s\n", argv[1]);
	printf("string len = %d\n", res);
	return (0);
}
