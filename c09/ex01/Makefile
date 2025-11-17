srcs/%.o: srcs/%.c includes/ft.h
	cc -Wall -Wextra -Werror -Iincludes -c $< -o $@

libft.a: srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
	ar rcs $@ $^

all: libft.a

clean:
	rm -f srcs/*.o

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re