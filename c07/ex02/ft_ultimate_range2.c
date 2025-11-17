#include <stdlib.h>
int ft_ultimate_range(int **range, int min, int max)
{
    long length;
    int *range_start;

    length = (long)max - (long)min;
    if (length <= 0)
    {
        *range = NULL;
        return (0);
    }
    *range = malloc(sizeof(**range) * length);
    if (!*range)
        return (-1);
    range_start = *range;
    while (min < max)
    {
        **range = min;
        (*range)++;
        min++;
    }
    *range = range_start;
    return ((int)length);
}

#include <stdio.h>
int main()
{
    int* arr;
    int len = ft_ultimate_range(&arr, 1, 10);
    
    printf("\nres: ");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
}