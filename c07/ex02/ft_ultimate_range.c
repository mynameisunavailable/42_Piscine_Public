#include <stdlib.h>
int ft_ultimate_range(int **range, int min, int max)
{
    long difference;
    long count;

    difference = (long)max - (long)min;
    if (difference <= 0) 
    {
        *range = NULL;
        return (0);
    }
    *range = malloc(sizeof(**range) * difference);
    if (*range == NULL) return (-1);
    count = 0;
    while (difference > count)
    {
        (*range)[count] = min + count;
        count++;
    }
    return ((int)difference);
}

