int	ft_is_white_space(char base)
{
	if (base == ' ' || base == '\f' || base == '\n'
		|| base == '\r' || base == '\t' || base == '\v')
		return (1);
	return (0);
}