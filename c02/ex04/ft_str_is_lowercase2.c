/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:45:47 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/05 19:45:55 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (*str < 'a' || 'z' < *str)
			return (0);
		str++;
	}
	return (1);
}

// #include <stdio.h>
// int main(void)
// {
// 	// char *str = "99";
// 	int code;

// 	code = ft_str_is_lowercase("");
// 	printf("%d\n", code);

// 	code = ft_str_is_lowercase("str");
// 	printf("%d\n", code);

// 	code = ft_str_is_lowercase("sTr");
// 	printf("%d\n", code);

// 	code = ft_str_is_lowercase("99");
// 	printf("%d\n", code);
// 	return (0);
// }
