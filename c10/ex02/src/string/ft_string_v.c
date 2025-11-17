int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!('a' <= *str && *str <= 'z')
			&& !('A' <= *str && *str <= 'Z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	ft_str_is_lower(char *str)
{
	while (*str)
	{
		if (*str < 'a' || 'z' < *str)
			return (0);
		str++;
	}
	return (1);
}

int	ft_str_is_upper(char *str)
{
	while (*str)
	{
		if (*str < 'A' || 'Z' < *str)
			return (0);
		str++;
	}
	return (1);
}

int	ft_str_is_num(char *str)
{
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (0);
		str++;
	}
	return (1);
}

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || 126 < *str)
			return (0);
		str++;
	}
	return (1);
}