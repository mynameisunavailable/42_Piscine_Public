/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:50:13 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/06 15:46:29 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0)
	{
		if ((*s1 != *s2) || (*s1 == '\0'))
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char *s1 = "app";
	char *s2 = "appricot";
	printf("%d,\n", strncmp(s1, s2, 0));
	printf("%d,\n", ft_strncmp(s1, s2, 0));
	printf("%d,\n", strncmp(s1, s2, 1));
	printf("%d,\n", ft_strncmp(s1, s2, 1));
	printf("%d,\n", strncmp(s1, s2, 3));
	printf("%d,\n", ft_strncmp(s1, s2, 3));
	printf("%d,\n", strncmp(s1, s2, 5));
	printf("%d,\n", ft_strncmp(s1, s2, 5));
	printf("%d,\n", strncmp(s1, s2, 8));
	printf("%d,\n", ft_strncmp(s1, s2, 8));
	printf("%d,\n", strncmp(s1, s2, 50));
	printf("%d,\n", ft_strncmp(s1, s2, 50));
}
