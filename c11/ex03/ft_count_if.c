int ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int c;
	int v;

	i = 0;
	c = 0;
	while (i < length)
	{
		v = f(tab[i]);
		if (v)
		{
			c++;
		}
		i++;
	}
	return (c);
}