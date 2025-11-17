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

char	*ft_strstr(char *str, char *to_find)
{
	char *str_temp;
	char *to_find_temp;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		str_temp = str;
		to_find_temp = to_find;
		while ((*str_temp == *to_find_temp) && *str_temp)
		{
			str_temp++;
			to_find_temp++;
		}
		if (*to_find_temp == '\0')
			return (str);
		str++;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>

int main() {
	char *text = "Welcome to the tea party.";
	char *word = "tea";

	char *result = ft_strstr(text, word);

	if (result)
		printf("Found at: %s\n", result);
	else
		printf("Not found.\n");
	printf("1%s\n", strstr("hello","ell"));
	printf("1%s\n", ft_strstr("hello","ell"));

	printf("2%s\n", strstr("hello","ella"));
	printf("3%s\n", ft_strstr("hello","ella"));

	printf("4%s\n", strstr("hello",""));
	printf("5%s\n", ft_strstr("hello",""));
	return 0;
}
