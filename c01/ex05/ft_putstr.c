/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:26:20 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/05 14:51:08 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

// #include <stdio.h>
// int	main(void)
//  {
//     // char x = "abc";
//     char *a = "apple";

//     // printf("%s\n", a);
//     ft_putstr(a);
//     // printf("%s\n", a);
//     return (0);
//  }
