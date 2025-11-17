/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:50:42 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/07 18:03:53 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
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

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		count;
	char	*start;
	char	chara;

	// start = base;
	count = 0;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return ;//if function is empty or only one char then do nothing
	while (*base)
	{
		base++;
		chara = base[count];
		if (ft_strstr(base, &chara) != NULL)
		{
			printf("found\n");
			return ;
		}
		count++;
	}
	printf("not found\n");
	return ;

	// if (chara )
}


// • The function must handle negative numbers.
//  • If an invalid argument is provided, nothing should be displayed.
//  Examples of invalid arguments:
//  ◦ The base is empty or has only one character.
//  ◦ The base contains duplicate characters.
//  ◦ The base contains ‘+’ or ‘-’.

int main()
{
	char *base = "0123456789";
	// char *base = "0113456789";

	printf("%s\n", base);
	ft_putnbr_base(5, base);
	return (0);
}
