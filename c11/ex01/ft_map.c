#include <stdlib.h>

// int ft_putnbr_int_rec(int nb)
// {
// 	nb += 1;
// 	return nb;
// }

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int *arr;
	int i;

	if (!tab || length < 1)
		return (NULL);
	arr = malloc(length * sizeof(*tab));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}

// #include <stdio.h>
// int	main()
// {
// 	int arr[] = {22, 33 ,11};
// 	int *arr1 = ft_map(arr, 3, ft_putnbr_int_rec);
// 	printf("%d\n", arr[0]);
// 	printf("%d", arr1[0]);
// }