#!/bin/sh
# gcc -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
gcc -c *.c
ar rcs libft.a *.o