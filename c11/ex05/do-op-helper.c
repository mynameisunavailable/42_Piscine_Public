#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_str_is_num(char *str)
{
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	digit;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}
	return (sign * result);
}

void ft_putnbr(int nb)
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
        ft_putnbr((int)(negative * (nb / 10)));
    }
	write(1, &digit, 1);
}


void    ft_putstr(const char *str)
{
    while (*str)
    {
        write(1, &(*str), 1);
        str++;
    }    
}