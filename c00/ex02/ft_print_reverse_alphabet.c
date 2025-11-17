#include <sys/stat.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_reverse_alphabet(void)
{
    char    c;
    int     i;
    
    c = 'z'; //breakhere
    i = 0;
    while (i < 26)
    {
        ft_putchar(c - i);
        i++;
    }
}

// int main() {
//     ft_print_reverse_alphabet();
//     return 0;
// }