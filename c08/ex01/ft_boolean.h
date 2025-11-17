typedef int t_bool;
#define TRUE 1
#define FALSE 0

int EVEN(int nbr)
{
    if (nbr % 2 == 0)
    {
        return (TRUE);
    }
    return (FALSE);
}

#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
#define SUCCESS 0