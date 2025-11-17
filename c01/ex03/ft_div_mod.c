/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:25:59 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/01 14:29:10 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>
// int main(void)
// {
// 	int a = 42;
// 	int b = 3;
// 	int *div = &a;
// 	int *mod = &b;

// 	printf("%d, %d\n", *div, *mod);
// 	ft_div_mod(a ,b, div, mod);
// 	printf("%d, %d\n", *div, *mod);
// 	return (0);
// }
