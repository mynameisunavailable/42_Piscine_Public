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
	char *dest_start;

	dest_start = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	
	return (dest_start);
}

// #include <stdio.h>
// int main()
// {
// 	char s1[100] = "app";
// 	char *s2 = "appricot";
// 	ft_strcat(s1, s2);
// 	printf("%s\n", s1);
// }
