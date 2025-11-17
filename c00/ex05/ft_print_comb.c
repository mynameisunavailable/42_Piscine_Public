#include <sys/stat.h>
#include <unistd.h>

void    ft_reverse_string(char *string, char *reverse_string, int length)
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

char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

void    ft_itoa_dec(int n, char *string)
{
    int i;
    long long num;
    char reverse_string[12];
    int negative;

    negative = (n < 0);
    i = 0;
    num = (long long)n;
    if (num < 0)
        num = -num;
    else if (num == 0)
        string[i++] = '0';
    while (num > 0)
    {
        string[i++] = '0' + (num % 10);
        num = num / 10;
    }
    if (negative)
        string[i++] = '-';
    string[i] = '\0';
    ft_reverse_string(string, reverse_string, i);
    ft_strcpy(string, reverse_string);
}

void    ft_putnbr(int nb)
{
    char nb_string[12];
    int i;
    
    ft_itoa_dec(nb, nb_string);
    i = 0;
    while (nb_string[i])
    {
        write(1, &(nb_string[i]), 1);
        i++;
    }
}

void    ft_print_comb(void)
{
    int hundreds;
    int tens;
    int ones;

    hundreds = 0;
    while (hundreds <= 9)
    {
        tens = hundreds + 1;
        while (tens <= 9)
        {
            ones = tens;
            while (++ones <= 9)
            {
                ft_putnbr(hundreds);
                ft_putnbr(tens * 10 + ones);
                if (!(hundreds == 7 && tens == 8 && ones == 9))
                    write(1, ", ", 2);
            }
            tens++;
        }
        hundreds++;
    }
}

// int main(){
//     ft_print_comb();
//     return 0;
// }