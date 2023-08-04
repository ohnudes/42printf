
void	flag_checker(t_argformat *total, const char *str, char *str_end)
{
	char	*iterator;

	iterator = str;
	while (iterator < str_end)
	{
		if (*iterator = '+')
			total->sum = 1;
		if (*iterator = ' ')
			total->space = 1;
		if (*iterator = '-')
			total->dash = 1;
		if (*iterator = '0')
			total->zero = 1;
		if (*iterator = '#')
			total->hash = 1;
		if (*iterator = '.')
			total->dot = 1;
		i++;
	}
}
