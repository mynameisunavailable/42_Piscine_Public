/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:35:22 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/11 12:55:36 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BASE_NBR_SIZE (32 * 6)

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_reverse_string(char *string, char *reverse_string, int length)
{
    int index;
    
    index = 0;
    while (length > 0)
    {
        reverse_string[index] = string[length - 1];
        length--;
        index++;
    }
    reverse_string[index] = '\0';
}

void	ft_convert_to_base(int n, char *base, int base_size, char *base_nbr_string)
{
	int i;
	char reverse_base_string[BASE_NBR_SIZE];
	int negative;

	negative = 1;
	if (n < 0)
		negative = -1;
	i = 0;
	while ((n <= -base_size) || (base_size <= n))
	{
		reverse_base_string[i] = base[negative * (n % base_size)];
		n = n / base_size;
		i++;
	}
	reverse_base_string[i++] = base[negative * (n % base_size)];
	if (negative == -1)
		reverse_base_string[i++] = '-';
	reverse_base_string[i] = '\0';

	ft_reverse_string(reverse_base_string, base_nbr_string, i);
}

int	bitmask_ckrep(char* word, unsigned char* mask)
{
	unsigned char *c;
	
    while (*word)
    {
		c = (unsigned char *)word;
        if ((mask[*c / 8]) & (1U << (*c % 8)))
            return (1);
        else
            mask[*c / 8] = mask[*word / 8] | (1U << (*c % 8));
        word++;
    }
    return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char base_nbr_string[BASE_NBR_SIZE];
	int base_size;
	unsigned char mask[32] = {0};
	int c;

	base_size = ft_strlen(base);
	if (base_size <= 1)
		return ;
	if (bitmask_ckrep(base, mask))
		return ;
	c = 0;
	while (base[c])
	{
		if (base[c] == '+' || base[c] == '-')
			return ;
		c++;
	}
	ft_convert_to_base(nbr, base, base_size, base_nbr_string);
	c = 0;
	while (base_nbr_string[c])
		write(1, &base_nbr_string[c++], 1);
}

int main()
{
	ft_putnbr_base(16, "0123456789ABCDEF"); //10
	write(1, "\n", 1);
	ft_putnbr_base(42, "0123456789ABCDEF"); //2A
	write(1, "\n", 1);
	ft_putnbr_base(955, "0123456789ABCDEF"); //3BB
	write(1, "\n", 1);
	ft_putnbr_base(-955, "0123456789ABCDEF"); //-3BB
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "0123456789ABCDEF"); //-80000000
	write(1, "\n", 1);
	ft_putnbr_base(-2147483647, "0123456789ABCDEF"); //-7FFFFFFF
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "0123456789ABCDEF"); //7FFFFFFF
	write(1, "\n", 1);
	ft_putnbr_base(1000000000, "0123456789ABCDEF"); //3B9ACA00
	write(1, "\n", 1);
	ft_putnbr_base(-1000000000, "0123456789ABCDEF"); //-3B9ACA00
	write(1, "\n", 1);
	ft_putnbr_base(0, "0123456789ABCDEF"); //0

	return 0;
}
