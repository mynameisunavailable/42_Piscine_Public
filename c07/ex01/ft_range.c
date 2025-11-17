#include <stdlib.h>

int *ft_range(int min, int max)
{
    long difference;
    long count;
    int *range;
    
    difference = (long)max - (long)min;
    if (difference <= 0) 
        return (NULL);
    range = malloc(sizeof(*range) * difference);
    if (range == NULL)
        return (NULL);
    count = 0;
    while (difference > count)
    {
        range[count] = min + count;
        count++;
    }
    return (range);
}