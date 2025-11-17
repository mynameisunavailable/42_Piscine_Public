#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
    char *dest_start;
    
    dest_start = dest;
    while(*src)
        *dest++ = *src++;
    *dest = '\0';
    return(dest_start);
}

void    release_mem(t_stock_str *res, int start, int end)
{
    while (start <= end)
    {
        free(res[start].str);
        free(res[start].copy);
        start++;
    }
    free(res);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    int i;
    t_stock_str *res;

    res = malloc(sizeof(t_stock_str) * (ac + 1));
    if (!res)
        return (NULL);
    i = 0;
    while (i < ac)
    {
        res[i].size = ft_strlen(av[i]);
        res[i].str = ft_strdup(av[i]);
        res[i].copy = ft_strdup(av[i]);
        if (!res[i].str || !res[i].copy)
        {
            release_mem(res, 0, i);
            return (NULL);
        }
        i++;
    }
    res[i].str = 0;
    return (res);
}


//remove
// typedef struct s_stock_str
// {
//     int size;
//     char *str;
//     char *copy;
// }               t_stock_str;
