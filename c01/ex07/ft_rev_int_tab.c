/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:26:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/01 14:52:30 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp_arr[999];
	int	count;
	int	index;

	count = 0;
	index = size - 1;
	while (index >= count)
	{
		temp_arr[count] = tab[index - count];
		count++;
	}
	count = 0;
	while (index >= count)
	{
		tab[count] = temp_arr[count];
		count++;
	}
}

// int main()
// {
//     int tab[] = {7,1,2,3,5,6};

//     ft_rev_int_tab(&tab[0], 6);
//     for (int i = 0; 6 > i; i++)
//     {
//         printf("%d", tab[i]);
//     }
//     return (0);
// }
