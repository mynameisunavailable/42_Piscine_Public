#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char *dest_start;

	dest_start = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	
	return (dest_start);
}

//res_len = 1; null ending
int ft_strs_total_len(int size, char **strs, char *sep)
{
    int res_len;
    int sep_len;
    int i;

    res_len = 1; 
    i = 0;
    if (strs == NULL)
        return (-1);
    while (i < size)
    {
        if (strs[i] == NULL)
            return (-1);
        res_len += ft_strlen(strs[i]);
        i++;
    }
    if (sep == NULL)
        return (-1);
    sep_len = ft_strlen(sep);
    res_len += sep_len * (size - 1);
    return (res_len);
}

//if res_len < 0 could be sep or strs is NULL or size is 0
char *ft_strjoin(int size, char **strs, char *sep)
{
    int res_len;
    char    *res;
    int count;

    res_len = ft_strs_total_len(size, strs, sep);
    if (res_len < 0)
    {
        res_len = 1;
        size = 0;
    }
    res = malloc(res_len * sizeof(**strs));
    if (!res)
        return (NULL);
    *res = '\0';
    count = 0;
    while (count < size)
    {
        ft_strcat(res, strs[count]);
        if (count++ != size - 1)
            ft_strcat(res, sep);
    }
    return (res);
}

// #include <stdio.h>
// int main()
// {
//     char *strs[] = {"cat", "nip", "time"};

//     char *comb_strs = ft_strjoin(3, strs, ": ;");
//     // char *comb_strs = ft_strjoin(1, strs, " ");

//     printf("%s", comb_strs);
//     free(comb_strs);

//     return (0);
// }