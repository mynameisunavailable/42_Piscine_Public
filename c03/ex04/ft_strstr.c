/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:08:31 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/06 16:39:26 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	if (n == 0)
		return (0);
	count = 0;
	while (*s1 && *s2 && *s1 == *s2 && count < n)
	{
		s1++;
		s2++;
		count++;
	}
	if (count == n)
	{
		return (0);
	}
	return (*s1 - *s2);
}

//go through each char of str and compare with
// the first char of to_find.
//if found then compare next char of str with
//second char of to_find.
//repeat until reaches '\0' of to_find
//if loop ends then return NULL since didn't find
//if to_find is empty string, return value is str.
char	*ft_strstr(char *str, char *to_find)
{
	int	length;

	if (*to_find == '\0')
		return (str);
	length = ft_strlen(to_find);
	while (*str)
	{
		if (ft_strncmp(str, to_find, length) == 0)
			return (str);
		str++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
// 	char *text = "Welcome to the tea party.";
// 	char *word = "tea";

// 	char *result = ft_strstr(text, word);

// 	if (result)
// 		printf("Found at: %s\n", result);
// 	else
// 		printf("Not found.\n");
// 	printf("1%s\n", strstr("hello","ell"));
// 	printf("1%s\n", ft_strstr("hello","ell"));

// 	printf("2%s\n", strstr("hello","ella"));
// 	printf("3%s\n", ft_strstr("hello","ella"));

// 	printf("4%s\n", strstr("hello",""));
// 	printf("5%s\n", ft_strstr("hello",""));
// 	return 0;
// }
