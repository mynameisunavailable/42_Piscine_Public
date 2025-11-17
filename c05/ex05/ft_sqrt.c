/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:24:38 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/09 16:25:12 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	count;
	int	product;

	count = 1;
	product = 0;
	while (product < nb)
	{
		product = count * count;
		count++;
	}
	if (product == nb)
		return (count - 1);
	else
		return (0);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_sqrt(-1));
// 	printf("%d\n", ft_sqrt(0));
// 	printf("%d\n", ft_sqrt(1));
// 	printf("%d\n", ft_sqrt(2));
// 	printf("%d\n", ft_sqrt(3));
// 	printf("%d\n", ft_sqrt(4));
// 	printf("%d\n", ft_sqrt(5));
// 	printf("%d\n", ft_sqrt(6));
// 	printf("%d\n", ft_sqrt(16));
// 	printf("%d\n", ft_sqrt(144));
// }
