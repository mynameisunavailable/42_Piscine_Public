void	ft_convert_to_base(long n, char *base, int base_size)
{
	if (n >= base_size)
	{
		ft_convert_to_base(n / base_size, base, base_size);
	}
	write(1, &base[n % base_size], 1);
	return ;
}

int	ft_check_duplicate_char(char c, char *s1)
{
	while (*s1)
	{
		if (c == s1[0])
		{
			return (1);
		}
		s1++;
	}
	return (0);
}


int	ft_check_signs_and_space(char *base)
{
	while (*base)
	{
		if (*base == '+' || *base == '-')
		{
			return (1);
		}
		if (*base == ' ' || *base == '\f' || *base == '\n'
			|| *base == '\r' || *base == '\t' || *base == '\v')
			return (1);
		base++;
	}
	return (0);
}

long	ft_check_char_pos_in_str(char *str, char *base_str)
{
	int		count;
	int		base_len;
	long	result;

	base_len = ft_strlen(base_str);
	result = 0;
	while (*str)
	{
		count = 0;
		while (base_str[count] && *str != base_str[count])
			count++;
		if (base_str[count] == '\0')
			break ;
		result = result * base_len + count;
		str++;
	}
	return (result);
}