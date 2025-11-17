/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:25:58 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/01 14:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// printf("number: %d\n", min);
// delete the min number, by moving everything to the right
// of the min number to the left by one
void	ft_shift_left_from_index(int index, int size, int *tab)
{
	while (size - 1 > index)
	{
		tab[index] = tab[index + 1];
		index++;
	}
}

void	ft_copy_array(int size, int *o_arr, int *c_arr)
{
	int	count;

	count = 0;
	while (count < size)
	{
		c_arr[count] = o_arr[count];
		count++;
	}
}

int	ft_output_min(int size, int temp_count, int *tab)
{
	int	index;
	int	min;
	int	min_index;

	min = tab[0];
	min_index = 0;
	index = 0;
	while (index < size - temp_count)
	{
		if (tab[index] < min)
		{
			min = tab[index];
			min_index = index;
		}
		index++;
	}
	return (min_index);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp_arr[9999];
	int	temp_count;
	int	min;
	int	min_index;

	temp_count = 0;
	while (temp_count < size)
	{
		min_index = ft_output_min(size, temp_count, tab);
		min = tab[min_index];
		ft_shift_left_from_index(min_index, size, tab);
		temp_arr[temp_count] = min;
		temp_count++;
	}
	ft_copy_array(size, temp_arr, tab);
}

// int main(void)
// {
//     int tab[] = {1,4,2,3,6,1,55,11};
//     int size = 8;

//     ft_sort_int_tab(tab, size);
//     printf("tab:");

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", tab[i]);
//     }
//     printf("\n");
//     return (0);
// }
