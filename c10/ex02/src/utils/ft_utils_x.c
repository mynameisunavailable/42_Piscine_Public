void	ft_swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void    ft_swap_str(char **a, char **b)
{
    char *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}