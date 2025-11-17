#include <sys/stat.h>
#include <unistd.h>

void    ft_putstr(char *str)
{
    while (*str)
    {
        write(1, &(*str), 1);
        str++;
    }    
}

int islastnum(char *buffer, int buffer_index)
{
	char c;
	char d;

	buffer_index--;
	if (buffer[buffer_index] != '9')
	{
		return (0);
	}
	while (buffer_index > 0)
	{
		c = buffer[buffer_index];
		d = buffer[buffer_index - 1];
		if (c != d + 1)
		{
			return 0;
		}
        buffer_index--;
	}
	return 1;
}

void    ft_print_comb_rec(int num_of_digits, int current_start, char *buffer, int buffer_index)
{
	if (num_of_digits == 1)
	{
		while (current_start <= 9)
		{
			buffer[buffer_index++] = current_start + '0';
            buffer[buffer_index] = '\0';
			ft_putstr(buffer);
			if (!islastnum(buffer, buffer_index))
                write(1, ", ", 2);
			current_start++;
			buffer_index--;
		}
	}
	else
	{
		while (current_start <= 9)
		{
			buffer[buffer_index] = current_start + '0';
			ft_print_comb_rec(num_of_digits - 1, current_start + 1, buffer, buffer_index + 1);
			current_start++;
		}	
	}
}

void    ft_print_combn(int n)
{
    char buffer[12];
    
    ft_print_comb_rec(n, 0, buffer, 0);
}

// #include <stdio.h>
// int main()
// {
//     // ft_print_combn(1);
//     // ft_print_combn(2);
//     ft_print_combn(3);
//     // ft_print_combn(4);
//     // ft_print_combn(5);
//     // ft_print_combn(6);
//     // ft_print_combn(7);
//     // ft_print_combn(8);
//     // ft_print_combn(9);
    
//     return (0);
// }