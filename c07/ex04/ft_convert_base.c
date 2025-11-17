#include <stdlib.h>
#include <limits.h>

void ft_reverse_string(char *string, char *reverse_string, int length);
int	ft_is_white_space(char base);
int	bitmask_ckrep(char* word, unsigned char* mask);
unsigned int	ft_strlen(char *str);

// if (res < INT_MIN || res > INT_MAX) return (NULL);
int	base_to_int(char *str, char *base)
{
	int	i;
	int	res;
	int	base_len;

	base_len = ft_strlen(base);
	res = 0;
	while (*str)
	{
		i = 0;
		while (i < base_len && base[i] != *str)
			i++;
		if (i == base_len)
			break;
		res = res * base_len + i;
		str++;
	}
	return (res);
}

//malloc check NULL
char    *ft_convert_to_base(int n, char *base)
{
	int     i;
	char    reverse_base_string[33 + 1];
	int     negative;
    int     base_size;
    char    *base_nbr_string;

    base_size = ft_strlen(base);
	negative = 1;
	if (n < 0)
		negative = -1;
	i = 0;
	while ((n <= -base_size) || (base_size <= n))
	{
		reverse_base_string[i++] = base[negative * (n % base_size)];
		n = n / base_size;
	}
	reverse_base_string[i++] = base[negative * (n % base_size)];
	if (negative == -1)
		reverse_base_string[i++] = '-';
    base_nbr_string = malloc((i + 1) * sizeof(char));
    ft_reverse_string(reverse_base_string, base_nbr_string, i);
	return (base_nbr_string);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned char	mask[32] = {0};
	int				i;
	int				negative;

	if (ft_strlen(base) <= 1 || bitmask_ckrep(base, mask))
		return (0);
	i = 0;
	while (i < (int)ft_strlen(base))
	{
		if (ft_is_white_space(base[i]) || base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	while (ft_is_white_space(*str))
		str++;
	negative = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			negative = -negative;
	}
	return (negative * base_to_int(str, base));
}

int ft_check_base_valid(char *base)
{
    int base_len;
    int i;
	unsigned char	mask[32] = {0};

    base_len = ft_strlen(base);
    if (base_len <= 1 || bitmask_ckrep(base, mask)) return (0);
	i = 0;
	while (i < base_len)
	{
		if (ft_is_white_space(base[i]) || base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
    return (1);    
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int     dec;
    char    *res;

    if (!ft_check_base_valid(base_from) || !ft_check_base_valid(base_to))
        return (NULL);
    dec = ft_atoi_base(nbr, base_from);

    res = ft_convert_to_base(dec, base_to);
    return (res);
}

// #include <stdio.h>
// int main()
// {
// 	char *str = ft_convert_base("cab", "abc", "0123456789");
//     printf("%s\n", str);
// 	// str = ft_convert_base("  -+-BB", "0123456789ABCDEF", "0123456789");
// 	// if (str == NULL)
//     // {
//     //     printf("NULL");
//     // }
//     // printf("%s\n", str);
// }
