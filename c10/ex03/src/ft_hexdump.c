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
#include "bool/ft_bool.h"
#include "utils/ft_utils.h"

#include <stdio.h>

#define READ_SIZE (16)

void    read_file_error(char *filename)
{
    ft_puterr("ft_tail: ");
    ft_puterr(basename(filename));
    ft_puterr(": ");
    ft_puterr(strerror(errno));
    ft_puterr("\n");
}

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

typedef struct s_hexd_cmd
{
    char    *fcmd;
    t_bool  C_avail;
    char    buf[READ_SIZE];
    int gt;
    unsigned int    offset;
}   s_hexd_cmd;

int initialise_cmd(s_hexd_cmd *cmd)
{
	cmd->fcmd = "C";
    cmd->C_avail = false;
    cmd->buf[0] = '\0';
    cmd->gt = 0;
    cmd->offset = 0;
    return (0);
}

//-1 error opening file
//-2 error reading file
int run_hexdump(const char *filename, s_hexd_cmd *cmd)
{
    int f_handle;
    int temp_gt;

    f_handle = open(filename, O_RDONLY);
    if (f_handle < 0)
    {
        read_file_error((char *)filename);
        return (-1);
    }
    temp_gt = read(f_handle, (cmd->buf + cmd->gt), (READ_SIZE - cmd->gt));
    if (temp_gt < 0)
    {
        read_file_error((char *)filename);
        return (-2);
    }
    cmd->gt += temp_gt;
    while (cmd->gt > (READ_SIZE - 1))
    {
        ft_print_hexdump(cmd->buf, cmd->gt, cmd->offset);
        cmd->offset += cmd->gt;
        cmd->gt = read(f_handle, cmd->buf, READ_SIZE);
    }
    close(f_handle);
    return (0);
}

int fetch_command_C(int argc, const char **argv, s_ft_getopt_o *opt, s_hexd_cmd *cmd)
{
    while (ft_getopt(argc, argv, opt, cmd->fcmd) != -1)
    {
        if (opt->res == 'C')
        {
            cmd->C_avail = true;
        }
    }
    if (cmd->C_avail == false)
    {
        return (-1);
    }    
    return (0);
}

int main (int argc, const char **argv)
{
    s_ft_getopt_o opt;
    s_hexd_cmd    cmd;

    initialise_cmd(&cmd);
    initialise_opt(&opt);
    if (fetch_command_C(argc, argv, &opt, &cmd) == -1)
    {
        write(2, "no supported commands present", 29);
        return (-1);
    }
    initialise_opt(&opt);
    while (ft_getopt(argc, argv, &opt, cmd.fcmd) != -1)
    {
        if (opt.res == 0)
        {
            if (cmd.C_avail == true)
            {
                run_hexdump(opt.arg, &cmd);
            }
        }
    }
    if (cmd.gt > 0)
        ft_print_hexdump(cmd.buf, cmd.gt, cmd.offset);
    ft_phd_offset(cmd.gt + cmd.offset);
    return (0);
}
