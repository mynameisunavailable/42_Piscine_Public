#include <stdio.h>

    //turn array size into array index
    //ensure all 4 stuff in the array is passed through
    // printf("complete\n");

    // for (int i = 0; 4 > i; i++)
    // {
    //     printf("%d", temp_arr[i]);
    // }
void   ft_rev_int_tab(int *tab, int size)
{
    int temp_arr[size];
    int count;


    for (int i = 0; 4 > i; i++)
    {
        printf("%d", tab[i]);
    }    
    printf("\n");

    count = 0;
    size = size - 1;
    while(size >= 0)
    {
        temp_arr[count] = tab[size];
        count++;
        size--;
    }
    
    size = size + 1;
    count = count -1;
    printf("%d, %d\n",count, size);

    while (count >= 0)
    {
        tab[size] = temp_arr[size];
        printf("converted %d: %d, %d\n",size, tab[size+1], temp_arr[count]);
        size++;
        count--;
    }

    for (int i = 0; 4 > i; i++)
    {
        printf("%d", temp_arr[i]);
    }    
    printf("\n");

    for (int i = 0; 4 > i; i++)
    {
        printf("%d", tab[i]);
    }    
    printf("\n");

}

int main()
{
    int tab[] = {7,1,2,3};

    ft_rev_int_tab(&tab[0], 4);
    // printf("%d\n", i);
    //     for (int i = 0; 4 > i; i++)
    // {
    //     printf("%d", rev_tab[i]);
    // }
    return (0);
}