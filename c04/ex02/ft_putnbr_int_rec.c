#include <unistd.h>

void ft_putnbr_int_rec(int nb)
{
    int negative;
    char digit;

	negative = 1;
    if (nb < 0)
    {
        write(1, "-", 1);
		negative = -1;
    }    
	if (-10 < nb && nb < 10)
    {
		digit = nb * negative;
		digit = digit + '0';
    }
    else
    {
        digit = nb % 10;
        digit = digit * negative;
        digit = digit + '0';
        ft_putnbr_int_rec((int)(negative * (nb / 10)));
    }
	write(1, &digit, 1);
}