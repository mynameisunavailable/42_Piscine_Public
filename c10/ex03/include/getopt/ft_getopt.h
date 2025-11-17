#ifndef FT_GETOPT_H
#define FT_GETOPT_H

//arg = argument of the command
//x = argv first dimension
//y = argv second dimension
//err = error no.
//opt = command 
typedef struct s_ft_getopt_o
{
	const char	*arg;
	int			x;
	int			y;
	int			err;
	int			opt;
	int			res;
}	s_ft_getopt_o;

int ft_getopt(int argc, const char **argv, s_ft_getopt_o *opt, const char *optstring);


#endif