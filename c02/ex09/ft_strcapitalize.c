/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:51:02 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/07 14:20:11 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	ft_charcapitalize(char *str, )

char	*ft_strcapitalize(char *str)
{
	int		new_word;
	char	*ptr;

	ptr = str;
	new_word = 1;
	while (*str)
	{
		if (new_word == 1 && ('a' <= *str && *str <= 'z'))
			*str = *str - 32;
		else if (new_word == 0 && ('A' <= *str && *str <= 'Z'))
			*str = *str + 32;
		if (('0' <= *str && *str <= '9')
			|| ('a' <= *str && *str <= 'z')
			|| ('A' <= *str && *str <= 'Z'))
			new_word = 0;
		else
			new_word = 1;
		str++;
	}
	return (ptr);
}
