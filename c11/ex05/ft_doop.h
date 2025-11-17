#ifndef FT_DOOP_H
#define FT_DOOP_H

// operator_func.c
int	ft_plus(int	n1, int n2);
int	ft_minus(int n1, int n2);
int	ft_multiply(int n1, int n2);
int	ft_divide(int n1, int n2);
int	ft_modulo(int n1, int n2);

//do-op-helper.c
unsigned int	ft_strlen(char *str);
int	ft_str_is_num(char *str);
int	ft_atoi(char *str);
void ft_putnbr(int nb);
void    ft_putstr(const char *str);

#endif