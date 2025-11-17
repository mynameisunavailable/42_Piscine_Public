#include "ft_stock_str.h"
#include <unistd.h>

void    ft_putstr(char *str)
{
    while (*str)
    {
        write(1, &(*str), 1);
        str++;
    }    
}

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

void ft_show_tab(struct s_stock_str *par)
{
    int i;

    i = 0;
    while (par[i].str)
    {
        ft_putstr(par[i].str);
        write(1, "\n", 1);
        ft_putnbr_int_rec(par[i].size);
        write(1, "\n", 1);
        ft_putstr(par[i].copy);
        write(1, "\n", 1);
        i++;
    }
}