/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:54:27 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/06 16:05:10 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		count;
	char	*start;

	start = dest;
	count = 0;
	while (dest[count])
	{
		count++;
	}
	while (*src)
	{
		dest[count] = *src;
		count++;
		src++;
	}
	dest[count] = '\0';
	return (start);
}

// #include <stdio.h>
// int main()
// {
// 	char s1[100] = "app";
// 	char *s2 = "appricot";
// 	ft_strcat(s1, s2);
// 	printf("%s\n", s1);
// }
