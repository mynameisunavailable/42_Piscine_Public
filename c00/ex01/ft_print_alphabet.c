#include <sys/stat.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_alphabet(void)
{
    char    c;
    int     i;
    
    c = 'a';
    i = 0;
    while (i < 26)
    {
        ft_putchar(c + i);
        i++;
    }
}
// void ft_print_alphabet(void){
//     char *x = "abcdefghijklmnopqrstuvwxyz";
//     write(1, x, 26);
// }

// int main(){
//     ft_print_alphabet();
//     return 0;
// }