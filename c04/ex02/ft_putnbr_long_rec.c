#include <unistd.h>

void ft_putnbr_long_rec(int nb)
{
    long long num;
    char digit;

    num = (long long)nb;
    if (num < 0)
    {
        write(1, "-", 1);
		num = -num;
    }
    
	if (num < 10)
    {
        digit = num + '0';
    }
    else
    {
        digit = num % 10;
        digit = digit + '0';
        ft_putnbr_long_rec((int)(num / 10));
    }
	write(1, &digit, 1);
}