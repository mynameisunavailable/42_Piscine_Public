/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:21:20 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/01 14:50:19 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// int main(void)
// {
// 	int x = 3;
// 	int y = 42;
// 	int *a = &x;
// 	int *b = &y;

// 	printf("%d, %d\n", x, y);
// 	ft_swap(a, b);
// 	printf("%d, %d\n", x, y);
// 	return (0);
// }
