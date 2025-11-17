#include <stdlib.h>
#include "string/ft_string.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_reverse_string(char *string, char *reverse_string, int length)
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

//takes string[] return malloced reverse string
//caller free()
char    *ft_reverse_string_malloc(char *string)
{
    int length;
    char *string_p;
    char *reversed_string;
    int j;
    
    length = ft_strlen(string);
    reversed_string = malloc((length + 1) * (sizeof(char)));
    string_p = reversed_string;
    j = length - 1;
    while (j >= 0)
    {
        string_p = concat_char_insitu(string_p, string[j]);
        j--;
    }
    return reversed_string;
}