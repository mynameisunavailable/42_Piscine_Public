#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>
#include <limits.h>
#include "getopt/ft_getopt.h"
#include "string/ft_string.h"
#include "numconv/ft_numconv.h"
#include "math/ft_math.h"

#define READ_SIZE (128 * 220)

typedef struct s_tail_cmd
{
    int byte_size;
}   s_tail_cmd;

void    read_file_error(const char *filename);
int initialise_opt(s_ft_getopt_o *opt);
int initialise_cmd(s_tail_cmd *cmd);

int    check_file_size(const char *filename)
{
    int     rd;
    int     gt;
    char    str[READ_SIZE];
    int     str_size;
    int     res;

    str_size = sizeof(str);
    rd = open(filename, O_RDONLY);
    if (rd < 0)
        return (-1);
    gt = read(rd, str, str_size);
    res = gt;
    while (gt > 0)
    {
        gt = read(rd, str, str_size);
        res += gt;
    }
    if (gt < 0)
    {
        close(rd);
        return (-2);
    }
    close(rd);
    return (res);
}

void    read_file_from_nbyte(const char *filename, int start)
{
    int     rd;
    int     gt;
    char    str[READ_SIZE];
    int     str_size;

    str_size = sizeof(str);
    rd = open(filename, O_RDONLY);
    while (start > str_size)
    {
        read(rd, str, str_size);
        start -= str_size;
    }
    read(rd, str, start);
    gt = read(rd, str, str_size);
    while (gt > 0)
    {
        write(1, str, gt);
        gt = read(rd, str, str_size);
    }
    close(rd);
}

int fetch_command_c(int argc, const char **argv, s_ft_getopt_o *opt, s_tail_cmd *cmd)
{
    while (ft_getopt(argc, argv, opt, "c:") != -1)
    {
        if (opt->res == 'c')
        {
            cmd->byte_size = ft_atoi((char *)opt->arg);
            if ((cmd->byte_size < 0) || (cmd->byte_size > INT_MAX))
            {
                write(2, "invalid c arg", 13);
                cmd->byte_size = 0;
            }
        }
    }
    return (cmd->byte_size);
}

int ft_tail_filename(const char *filename, int filenum, s_tail_cmd *cmd)
{
    int filesize;
    int start_byte;

    if (filenum > 1)
    {
        ft_putstr("==> ");
        ft_putstr(filename);
        ft_putstr(" <==\n");
    }
    filesize = check_file_size(filename);
    if (filesize < 0)
        read_file_error(filename);
    start_byte = ft_max((filesize - cmd->byte_size), 0);
    read_file_from_nbyte(filename, (start_byte));
    return (0);
}

int main (int argc, const char **argv)
{
    int     filenum;
    s_ft_getopt_o opt;
    s_tail_cmd    cmd;

    initialise_cmd(&cmd);
    initialise_opt(&opt);
    fetch_command_c(argc, argv, &opt, &cmd);
    filenum = 0;
    initialise_opt(&opt);
    while (ft_getopt(argc, argv, &opt, "c:") != -1)
    if (opt.res == 0)
    {
        filenum++;
    }
    initialise_opt(&opt);
    while (ft_getopt(argc, argv, &opt, "c:") != -1)
    {
        if (opt.res == 0)
        {
            ft_tail_filename(opt.arg, filenum, &cmd);
        }
    }
    return (0);
}

// void    show_txt(int n_lines)
// {
//     char    output[READ_SIZE];
//     int     output_size;

//     while (((output_size = read(0, output, sizeof(output))) > 0) && (n_lines > 0))
//     {
//         write(1, output, output_size);
//         n_lines--;
//     }
// }