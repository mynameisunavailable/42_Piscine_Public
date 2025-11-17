#include <stdlib.h>
#include "string/ft_string.h"

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

char    *ft_strndup(char *src, unsigned int n)
{
    char *dest = malloc(sizeof(char) * (n + 1));
    char *dest_start;
    
    if (!dest)
        return (NULL);
    dest_start = dest;
    while(n > 0 && *src)
    {
        *dest++ = *src++;
        n--;
    }
    while (n > 0)
    {
        *dest++ = '\0';
        n--;
    }    
    *dest = '\0';
    return(dest_start);
}
