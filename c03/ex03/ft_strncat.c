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
	char			*start;
	unsigned int	i;

	start = dest;
	while (*dest)
	{
		dest++;
	}
	i = 0;
	while (*src && i < nb)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = '\0';
	return (start);
}

// #include <stdio.h>
// int main()
// {
// 	char s1[100] = "app";
// 	char *s2 = "appricot";
// 	ft_strncat(s1, s2, 5);
// 	printf("%s\n", s1);
// }
