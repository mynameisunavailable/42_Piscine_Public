/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:47:17 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/05 19:48:33 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || 126 < *str)
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

// 	code = ft_str_is_printable("");
// 	printf("%d\n", code);

// 	code = ft_str_is_printable("    ");
// 	printf("%d\n", code);

// 	code = ft_str_is_printable("sTr");
// 	printf("%d\n", code);

// 	code = ft_str_is_printable("99");
// 	printf("%d\n", code);
// 	return (0);
// }
