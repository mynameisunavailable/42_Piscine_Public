/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:06:01 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/06 16:03:21 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *dest_start;

	dest_start = dest;
	while (*dest)
		dest++;
	while (nb > 0 && *src)
	{
		*dest++ = *src++;
		nb--;
	}
	*dest = '\0';

	return (dest_start);
}

// #include <stdio.h>
// int main()
// {
// 	char s1[100] = "app";
// 	char *s2 = "appricot";
// 	ft_strncat(s1, s2, 5);
// 	printf("%s\n", s1);
// }
