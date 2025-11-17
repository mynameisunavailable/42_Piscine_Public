/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:24:02 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/06 14:53:01 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char *s1 = "apple";
//     char *s2 = "appricot";
//     printf("%d,\n", strcmp(s1, s2));
//     printf("%d,\n", ft_strcmp(s1, s2));

//     char *s3 = "appleddd";
//     char *s4 = "app";
//     printf("%d,\n", strcmp(s3, s4));
//     printf("%d,\n", ft_strcmp(s3, s4));
// }
