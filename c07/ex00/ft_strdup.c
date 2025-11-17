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

unsigned    int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int count;
    unsigned int src_len;

    src_len = 0;
    while (src[src_len])
    {
        src_len++;
    }   
    if (size > 0)
    {
        count = 0;
        while (count < size - 1 && src[count])
        {
            dest[count] = src[count];
            count++;
        }
        dest[count] = '\0';
    }
    return (src_len);
}

char    *ft_strdup(char *src)
{
    size_t length;
    char *dest;

    length = ft_strlen(src);
    dest = malloc((length + 1) * sizeof(char));
    if (dest == NULL)
        return NULL;
    ft_strlcpy(dest, src, (unsigned int) (length + 1));
    return (dest);
}