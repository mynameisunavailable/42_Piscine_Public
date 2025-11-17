/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:39:34 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/05 19:46:00 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	ft_str_is_numeric(char *str)
{
	int	length;
	int	count;

	length = ft_strlen(str);
	count = 0;
	if (*str == '\0')
		return (1);
	while (length > count)
	{
		if (str[count] < '0' || '9' < str[count])
		{
			return (0);
		}
		count++;
	}
	return (1);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_str_is_numeric("string");
// 	printf("string: %d\n", ft_str_is_numeric("string"));
// 	printf("string: %d\n", ft_str_is_numeric("999"));
// 	return (0);
// }
