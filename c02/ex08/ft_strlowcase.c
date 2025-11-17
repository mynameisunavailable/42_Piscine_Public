/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:49:48 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/05 19:50:01 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if ('A' <= str[count] && str[count] <= 'Z')
		{
			str[count] = str[count] + 32;
		}
		count++;
	}
	return (str);
}

// #include <stdio.h>
// int main()
// {
//     char str[] = "STring";
//     printf("%s\n", ft_strlowcase(str));

//     char str2[] = "STr3nG";
//     printf("%s\n", ft_strlowcase(str2));
// }
