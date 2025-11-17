/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:15:42 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/08 15:20:39 by yunguo           ###   ########.fr       */
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

int	ft_str_is_alpha(char *str)
{
	int	length;
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	length = ft_strlen(str);
	while (length > i)
	{
		if (!('a' <= str[i] && str[i] <= 'z')
			&& !('A' <= str[i] && str[i] <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
