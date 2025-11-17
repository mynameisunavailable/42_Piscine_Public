#include <stdlib.h>

int *ft_range(int min, int max)
{
    long length;
    int *arr;
    int *arr_start;

    length = (long)max - (long)min;
    if (length <= 0)
        return (NULL);
    arr = malloc(sizeof(int) * length);
    if (!arr)
        return (NULL);
    arr_start = arr;
    while (min < max)
    {
        *arr++ = min++;
    }
    return (arr_start);
}

#include <stdio.h>
int main()
{
    int* arr = ft_range(0, 10);
    
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    
}