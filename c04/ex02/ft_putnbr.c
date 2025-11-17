/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:39:59 by yunguo            #+#    #+#             */
/*   Updated: 2025/08/11 12:31:40 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>

long	ft_reverse_number(long nb)
{
	long	result;

	result = 0;
	while (nb > 0)
	{
		result = result * 10 + nb % 10;
		nb = nb / 10;
	}
	return (result);
}

void	ft_putnbr(int nb)
{
	long	digit;
	long	i;
	char	c;

	i = nb;
	if (i == 0)
	{
		(write(1, "0", 1));
		return ;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}
	i = i * 10 + 1;
	i = ft_reverse_number(i);
	while (i > 9)
	{
		digit = (i % 10) + '0';
		c = (char)digit;
		i = i / 10;
		write(1, &c, 1);
	}
}

// #include <stdio.h>
// int main(void)
// {
//     int cases[] = {
//         0, 7, -7, 10, 1000, -1000000000, 42, -42, 123456789, -987654321,
//         9090, 1010, 214748364, 2147483647, -2147483647, -2147483648
//     };
//     // run ft_putnbr and printf side-by-side for each
//     for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); ++i) {
//         int n = cases[i];
//         printf("n=%d -> \"", n); fflush(stdout);
//         ft_putnbr(n);
//         printf("\" (expected \"%d\")\n", n);
//     }
// }

// int main ()
// {
// 	int i = -425353;

// 	// printf("put number: ");
// 	// ft_putnbr(i);
// 	// write(1, "\n", 1);
// 	// ft_putnbr(0);
// 	// write(1, "\n", 1);
// 	// ft_putnbr(123);
// 	// write(1, "\n", 1);
// 	// ft_putnbr(-500);
// 	// write(1, "\n", 1);
// 	// ft_putnbr(50000);
// 	// write(1, "\n", 1);
// 	// ft_putnbr(-425353);
// 	// write(1, "\n", 1);
// 	// ft_putnbr(214748364);
// 	// write(1, "\n", 1);
// 	// ft_putnbr(2147483647);
// 	write(1, "\n", 1);
// 	ft_putnbr(-2147483647);
// 	write(1, "\n", 1);
// 	ft_putnbr(-2147483648);
// 	write(1, "\n", 1);

// 	// printf("reverse number: %d\n", ft_reverse_number(425353));
// 	// return (0);
// }
