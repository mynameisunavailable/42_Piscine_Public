#include "ft_doop.h"

int	str_is_0(char *str, char operator_c[], int i)
{
	if (ft_atoi(str) == 0)
	{
		if (operator_c[i] == '/')
		{
			ft_putstr("Stop : division by zero");
			return (4);
		}
		if (operator_c[i] == '%')
		{
			ft_putstr("Stop : modulo by zero");
			return (5);
		}
	}
	return (0);
}

//MSYS2_ARG_CONV_EXCL='*' ./do-op 25 '/' foo
int	main(int argc, char **argv)
{
	char	operator_c[] = {'+', '-', '/', '*', '%', '\0'};
	int		(*operator_f[])(int, int) = {&ft_plus, &ft_minus, &ft_divide, &ft_multiply, &ft_modulo};
	int		i;
	int		res;

	if (argc != 4)
		return (1);
	i = 0;
	while (operator_c[i] != '\0')
	{
		if (argv[2][0] == operator_c[i])
			break ;
		i++;
	}
	if (!operator_c[i] || ft_strlen(argv[2]) != 1)
	{
		ft_putstr("0");
		return (3);
	}
	if (str_is_0(argv[3], operator_c, i))
		return (-1);
	res = (operator_f[i])(ft_atoi(argv[1]), ft_atoi(argv[3]));
	ft_putnbr(res);
	return (0);
}