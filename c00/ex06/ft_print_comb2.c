#include <sys/stat.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_put2nbr(int n)
{
    int tens;
    int ones;
    
    tens = n / 10 + '0';
    ones = n % 10 + '0';
    write(1, &tens, 1);
    write(1, &ones, 1);
}

void    ft_print_comb2(void)
{
    int first;
    int second;
    
    first = 0;
    while (first <= 99)
    {
        second = first + 1;
        while (second <= 99)
        {
            ft_put2nbr(first);
            ft_putchar(' ');
            ft_put2nbr(second);
            if (!(first == 98 && second == 99))
            {
                ft_putchar(',');
                ft_putchar(' ');
            }
            second++;
        }
        first++;
    }    
}

// int main(){
//     ft_print_comb2();
//     return 0;
// }