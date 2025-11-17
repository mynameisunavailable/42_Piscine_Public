// #include <stdlib.h>
#include "bit/ft_bit.h"

int ft_btmsk_cins(char c, char *str)
{
    unsigned char mask[32] = {0};
    int a;

    while (*str)
    {
        a = (unsigned char)*str;
        mask[a / 8] = (mask[a / 8]) | (1u << (a % 8));
        str++;
    }
    a = (unsigned char)c;
    if (mask[a / 8] & (1u << (a % 8)))
    {
        return (1);
    }
    return (0);
}

//1 = word string has repeated char
//mask use "unsigned char mask[32] = {0};" for ASCII
int	ft_btmsk_ckrep_str(char* word, unsigned char* mask)
{
	unsigned char *c;
	
    while (*word)
    {
		c = (unsigned char *)word;
        if ((mask[*c / 8]) & (1U << (*c % 8)))
            return (1);
        else
            mask[*c / 8] = mask[*word / 8] | (1U << (*c % 8));
        word++;
    }
    return (0);
}

/* typedef struct
{
    const void      *buf;
    size_t          buf_len;
    size_t          elem_size;
    unsigned char   *mask;
    size_t          mask_bitlen;
    unsigned int    (*get_index)(const void *elem);
} s_btmsk_param;
 */

/* 
unsigned int    get_index_struct(const void *elem)
{
    return (((const s_struct*)elem)->id);
}
 */

// int	ft_btmsk_ckrep_any(const s_btmsk_param *p)
// {
//     size_t          i;
//     size_t          c;
//     unsigned char   *mask;
//     int             created_mask;

//     created_mask = 0;
//     mask = p->mask;
//     if (!mask)
//     {
//         mask = ft_calloc(((p->mask_bitlen + 7) / 8), 1);
//         if (!mask)
//             return (-1);
//         created_mask = 1;
//     }
//     i = 0;
//     while (i < p->buf_len)
//     {
//         c = p->get_index(p->buf + (i++ * p->elem_size));
//         if (mask[c / 8] & (1u << (c % 8)))
//             return (1);
//         mask[c / 8] |= 1u << (c % 8);
//     }
//     if (created_mask)
//         free(mask);    
//     return (0);
// }