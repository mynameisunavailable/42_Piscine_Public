#ifndef FT_STRING_H
#define FT_STRING_H

//ft_string.c
unsigned int	ft_strlen(char *str);
void    ft_reverse_string(char *string, char *reverse_string, int length);
char*   ft_reverse_string_malloc(char* string);

//ft_string_cat.c
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);


//ft_string_cmp.c
int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strstr(char *str, char *to_find);

//ft_string_con.c
char*   concat_char(char* string, char c);
char*   concat_char_insitu(char* string, char c);

//ft_string_cpy.c
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

//ft_string_m.c
char    *ft_strdup(char *src);
char    *ft_strndup(char *src, unsigned int n);

//ft_string_p.c
void    ft_putchar(char c);
void    ft_putstr(const char *str);
void    ft_puterr(char *str);
void    ft_putnstr(char *str, int n);
void    ft_putnbr_int_rec(int nb);

//ft_string_s.c
unsigned int    ft_strjoin_total_len(int size, char **strs, char *sep);
char            *ft_strjoin(int size, char **strs, char *sep);
unsigned int    find_split_count(char *str, char *charset);
char            **ft_split(char *str, char *charset);

//ft_string_v.c
int	ft_str_is_alpha(char *str);
int	ft_str_is_num(char *str);
int	ft_str_is_lower(char *str);
int	ft_str_is_upper(char *str);
int	ft_str_is_printable(char *str);

//ft_string_t.c
char	*ft_str_toupper(char *str);
char	*ft_str_tolower(char *str);
char	*ft_str_titlecase(char *str);


#endif