#ifndef FT_BIT_H
#define FT_BIT_H

// //ft_bit_set.c
// typedef struct
// {
//     const void      *buf;
//     size_t          buf_len;
//     size_t          elem_size;
//     unsigned char   *mask;
//     size_t          mask_bitlen;
//     unsigned int    (*get_index)(const void *elem)
// } s_btmsk_param;

//ft_bit_set.c
int ft_btmsk_cins(char c, char *str);
int	ft_btmsk_ckrep_str(char* word, unsigned char* mask);
// int	ft_btmsk_ckrep_any(const s_btmsk_param *p);

#endif