#include <unistd.h>
#include <stdint.h>

void	ft_convert_to_base(long long n, char *base, int base_size)
{
	if (n >= base_size)
	{
		ft_convert_to_base(n / base_size, base, base_size);
	}
	write(1, &base[n % base_size], 1);
	return ;
}

int num_of_digit_hex_to_dec(long long dec)
{
    int count;

    count = 0;
    while (dec > 15)
    {
        dec /= 16;
        count++;
    }
    count++;
    
    return count;
}

void	ft_num_to_2hex(unsigned int i)
{
	unsigned int	tens;
	unsigned int	ones;
	char			*hex_str;

	hex_str = "0123456789abcdef";
	tens = i / 16;
	ones = i % 16;
	write(1, &hex_str[tens], 1);
	write(1, &hex_str[ones], 1);
}

void    ft_print_mhc(void *addr, unsigned int size)
{
    char hex_str[17] = "0123456789abcdef";
    long long value = (uintptr_t) addr;
    write(1, "0000000000000000", 16 - num_of_digit_hex_to_dec(value));
    ft_convert_to_base(value, hex_str, 16);
    write(1, ": ", 2);
    int c;
    c = 0;
    while (c < 16)
    {
        if (c < size)
            ft_num_to_2hex(((unsigned char *)addr)[c]);
        else
            write(1, "  ", 2);
        if (c % 2 == 1)
            write(1, " ", 1);
        c++;
    }
    c = 0;
    while (c < size)
    {
        if (32 <= (((unsigned char *)addr)[c]) && (((unsigned char *)addr)[c]) <= 126)
            write(1, &((unsigned char *)addr)[c], 1);
        else
            write(1, ".", 1);
        c++;
    }
    write(1, "\n", 1);
}

void    *ft_print_memory(void *addr, unsigned int size)
{
    int count;
    void *addr_start;
    
    addr_start = addr;
    count = size;
    while (count > 16)
    {
        ft_print_mhc(addr, 16);
        addr = (unsigned char *)addr + 16;
        count -= 16;
    }
    if (count > 0)
    {
        ft_print_mhc(addr, count);
    }
    return (addr_start);
}

#include <stdio.h>
int main()
{
    // char *str;

    // str = "Bonjour les aminches...c. est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. .";
    // char *str = "Bonjour les aminches\t\n\tc\x07 est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\t\n\tlol.lol.\n. .";
    char *str =
    "Bonjour les amin"
    "ches\t\n\tc\x07 est fo"
    "u\tto"
    "ut\tce qu on "
    "peut faire avec\t"
    "\n\tprint_memory\n\n"
    "\n\tlol.lol\n ";
    ft_print_memory(str, 92);
}