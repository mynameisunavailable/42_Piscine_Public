#ifndef FT_MATH_H
#define FT_MATH_H

#define ABS(Value) ((Value) < 0 ? -(Value) : (Value))

//ft_math_c.c
int ft_find_num_len(int n);

//ft_math_m.c
int ft_max(int n1, int n2);
int ft_min(int n1, int n2);

//ft_math_u.c
int	ft_factorial(int nb);
int	ft_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int ft_range(int **range, int min, int max);

//ft_math_p.c
int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);


#endif