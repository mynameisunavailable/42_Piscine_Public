#include <stdio.h>
#include <unistd.h>

void    ft_convert_to_base (int n, char *base, int base_size)
{
    if (n >= base_size)
    {
        ft_convert_to_base(n / base_size, base, base_size);
        // write(1, &base[n % base_size], 1);
    }
    write(1, &base[n % base_size], 1);

    return ;
}

// void ft_convert_to_base(int n, char *base, int base_size)
// {
//     int digit;
//     char chara;
//     // char result;

//     if (n >= base_size && n % base_size != 0)
//     {    // printf("%c\n", ft_convert_to_base(n / base_size, base, base_size));
        
//         digit = n % base_size;
//         n = n - digit;
//         chara = base[digit];
//         // write (1, &chara, 1);
//         // printf("%c", chara);
//         ft_convert_to_base(n, base, base_size);
//         write(1, &chara, 1);
//         return ;
//         // return (ft_convert_to_base(n, base, base_size));
//     }
//     // else if (n < base_size)
//     else
//     {
//         digit = n / base_size;
//         chara = base[digit];
//         write (1, &chara, 1);
//         // ft_convert_to_base(n - digit, base, base_size);
//         return ;
//     }
// }

int main ()
{
    char *base = "0123456789ABCDEF";
    int base_size = 16;
    ft_convert_to_base(16, base, base_size); //expected 10
    write(1, "\n", 1);
    ft_convert_to_base(42, base, base_size); //expected 2A
    write(1, "\n", 1);
    ft_convert_to_base(955, base, base_size); //expected 3BB
    write(1, "\n", 1);
    // printf("%s\n", ft_convert_to_base(42, base, base_size)); // expected 2A
    return (0);
}