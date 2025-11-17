/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:13:50 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/06 18:01:35 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int count;

	count = 0;
	while (size > 0 && *dest)
	{
		dest++;
		count++;
		size--;
	}
	while (size > 1 && *src)
	{
		*dest++ = *src++;
		count++;
		size--;
	}
	while (*src++)
		count++;
	if (size > 0)
		*dest = '\0';
	return (count);
}

#include <stdio.h>
int	main()
{
	char s1[12] = "cat";
	char *s2 = "nips";
	int i;

	// i = ft_strlcat(s1, s2, 10);		//catnips 7
	i = ft_strlcat(s1, s2, 0);		//cat 4
	// i = ft_strlcat(s1, s2, 2);
	// i = ft_strlcat(s1, s2, 5);
	printf("%s\n", s1);
	printf("%d\n", i);
}
