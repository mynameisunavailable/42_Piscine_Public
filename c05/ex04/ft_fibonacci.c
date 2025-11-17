/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:20:16 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/09 16:24:25 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_fibonacci(-1));
// 	printf("%d\n", ft_fibonacci(0));
// 	printf("%d\n", ft_fibonacci(1));
// 	printf("%d\n", ft_fibonacci(2));
// 	printf("%d\n", ft_fibonacci(3));
// 	printf("%d\n", ft_fibonacci(4));
// 	printf("%d\n", ft_fibonacci(5));
// 	printf("%d\n", ft_fibonacci(6));
// 	printf("%d\n", ft_fibonacci(20));
// }
