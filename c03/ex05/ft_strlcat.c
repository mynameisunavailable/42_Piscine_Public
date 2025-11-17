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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	size_dest;
	unsigned int	size_src;

	size_src = ft_strlen(src);
	size_dest = ft_strlen(dest);
	count = 0;
	while (*dest && count < size)
	{
		dest++;
		count++;
	}
	if (count == size)
	{
		return (size + size_src);
	}
	while (*src && count < size - 1)
	{
		*dest = *src;
		count++;
		dest++;
		src++;
	}
	*dest = '\0';
	return (size_dest + size_src);
}
// #include <stdio.h>

// int	main()
// {
// 	char s1[12] = "cat";
// 	char *s2 = "nip";
// 	int i;

// 	i = ft_strlcat(s1, s2, 10);
// 	printf("%s\n", s1);
// 	printf("%d\n", i);
// }
