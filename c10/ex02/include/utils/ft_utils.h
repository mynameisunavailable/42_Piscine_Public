#ifndef FT_UTILS_H
#define FT_UTILS_H

//ft_utils_x.c
void	ft_swap_int(int *a, int *b);
void    ft_swap_str(char **a, char **b);

//ft_utils_pmem.c
void    ft_print_m(void *addr);
void    ft_print_hc(void *addr, unsigned int size);
void    *ft_print_memory(void *addr, unsigned int size);

//ft_utils_sort.c
void	ft_bubble_sort_from_n(char ***arr, int arr_c, size_t n);

#endif