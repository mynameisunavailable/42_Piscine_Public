/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:18:34 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/07 14:26:11 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (size > 0)
	{
		count = 0;
		while (count < size - 1 && src[count])
		{
			dest[count] = src[count];
			count++;
		}
		dest[count] = '\0';
	}
	return (src_len);
}
