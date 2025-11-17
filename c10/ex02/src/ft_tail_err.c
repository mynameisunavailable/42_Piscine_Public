#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>
#include "string/ft_string.h"

void    read_file_error(char *filename)
{
    ft_puterr("ft_tail: ");
    ft_puterr(basename(filename));
    ft_puterr(": ");
    ft_puterr(strerror(errno));
    ft_puterr("\n");
}
