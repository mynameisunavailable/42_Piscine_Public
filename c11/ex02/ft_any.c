int ft_any(char **tab, int(*f)(char*))
{
	int	i;
	int v;

	i = 0;
	while (tab[i])
	{
		v = f(tab[i]);
		if (v)
		{
			return (1);
		}
		i++;
	}
	return (0);
}