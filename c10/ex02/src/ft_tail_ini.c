#include "getopt/ft_getopt.h"
#include <stdlib.h>

int initialise_opt(s_ft_getopt_o *opt)
{
	opt->arg = NULL;
	opt->err = 0;
	opt->x = 1;
	opt->y = 1;
	opt->opt = 0;
	opt->res = 0;
    return (0);
}

typedef struct s_tail_cmd
{
    int byte_size;
}   s_tail_cmd;

int initialise_cmd(s_tail_cmd *cmd)
{
    cmd->byte_size = 0;
    return (0);
}
