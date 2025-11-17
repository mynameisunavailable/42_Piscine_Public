#include <unistd.h>
#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

// 1 = isspace, 0 = not space
int ft_isspace(char c)
{
    if (c == ' ' || c == '\f' || c == '\n'
        || c == '\r' || c == '\t' || c == '\v')
        return (1);
    else
        return (0);
}

//function check nbr valid
//skip is space
//compute '-' skip '+'

int ft_check_char_pos_in_str(char c, char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        if (c == *str)
        {
            return (count);
        }
        str++;
        count++;
    }
    return (-1);
}
//check if nbr all in base_from
//1 = valid, 0 = invalid
int ft_check_nbr_valid(char *nbr, char *base_from)
{
    char *base_from_start;
    int base_len;
    int count;

    if (ft_strlen(nbr) < 1)
        return (0);
    base_len = ft_strlen(base_from);
    base_from_start = base_from;
    while (*nbr)
    {
        if (ft_check_char_pos_in_str(*nbr, base_from) == -1)
            return (0);
        nbr++;
    }
    return (1);
}

int	ft_check_signs_and_space(char *base)
{
	while (*base)
	{
		if (*base == '+' || *base == '-')
		{
			return (1);
		}
		if (ft_isspace(*base) == 1)
			return (1);
		base++;
	}
	return (0);
}

char	*ft_strcat_char(char *dest, char src)
{
	int		count;
	char	*start;

	start = dest;
	count = 0;
	while (dest[count])
	{
		count++;
	}
    dest[count] = src;
	dest[count+1] = '\0';
	return (start);
}

//check if str has dup
int	ft_str_check_duplicate_char(char *s1)
{
    int count;
    int len_str;

    // len_str = ft_strlen(s1);
    count = 0;
	while (*s1)
	{
        count = 0;
        while (s1[count + 1])
        {
            if (*s1 == s1[count + 1])
                return (1);
            count++;
        }
		s1++;
	}
	return (0);
}

char	*ft_convert_to_base(long n, char *base, int base_size, char *final_result)
{
    // char *result;

    // final_result = malloc(sizeof(char) * 50);
    // if (final_result == NULL)
    //     return (NULL);
	if (n >= base_size)
	{
		ft_convert_to_base(n / base_size, base, base_size, final_result);
	}
    final_result = ft_strcat_char(final_result, (char)(base[n % base_size]));

	return final_result;
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int negative;

    negative = 1;
    while (*nbr)
    {
        if (*nbr == '-' || *nbr == '+' || ft_isspace(*nbr))
        {
            if (*nbr == '-')
                negative = -negative;
            nbr++;
        }
        else
            break;
    }
    if (ft_check_nbr_valid(nbr, base_from) == 0)
        return (NULL);


    //function check base_from valid
    //length > 2
    if (ft_strlen(base_from) < 2 || ft_strlen(base_to) < 2
        || ft_check_signs_and_space(base_from) == 1 || ft_check_signs_and_space(base_to) == 1
        || ft_str_check_duplicate_char(base_from) == 1 || ft_str_check_duplicate_char(base_to) == 1)
        return (NULL);


    //convert nbr to int using base_from
    int count;
    int result;
    result = 0;
	while (*nbr)
	{
		count = 0;
		while (base_from[count] && *nbr != base_from[count])
			count++;
		result = result * ft_strlen(base_from) + count;
		nbr++;
	}

    char *final_result;
    final_result = malloc(sizeof(char) * 50);
    if (negative < 0)
    {
        final_result[0] = '-';
    }
    else
        final_result[0] = '\0';
    //convert int to new_nbr using base_to
    return ((ft_convert_to_base((long)result, base_to, ft_strlen(base_to), final_result)));
}

#include <stdio.h>
int main()
{
	// int i = ft_convert_base("  -+--3BB", "0123456789ABCDEF", "01");
	// printf("%d\n", i);

    printf("%s\n" ,ft_convert_base("3BB", "0123456789ABCDEF", "0123456789")); //955
}