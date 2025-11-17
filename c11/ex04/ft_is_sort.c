int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	v;
	int ori;

	i = 0;
	while (i < (length - 1))
	{
		v = f(tab[i], tab[i + 1]);
		if (v != 0)
		{
			ori = v;
			break ;
		}
		i++;
	}
	while (i < (length - 1))
	{
		v = f(tab[i], tab[i + 1]);
		if (v != ori && v != 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}