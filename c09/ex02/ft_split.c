#include <stdlib.h>

char    *ft_strndup(char *src, unsigned int n)
{
    char *dest = malloc(sizeof(char) * (n + 1));
    char *dest_start;
    
    if (!dest)
        return (NULL);
    dest_start = dest;
    while(n > 0 && *src)
    {
        *dest++ = *src++;
        n--;
    }
    while (n > 0)
    {
        *dest++ = '\0';
        n--;
    }    
    *dest = '\0';
    return(dest_start);
}

int mask_cins(char c, char *str)
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

unsigned int    find_split_count(char *str, char *charset)
{
    int i;
    int c;
    int len;

    i = 0;
    c = 0;
    len = 0;
    while (str[i])
    {
        if (mask_cins(str[i], charset))
        {
            if (len > 0)
                c++;
            len = 0;
        }
        else
            len++;
        i++;
    }
    if (len > 0)
        c++;
    return (c + 1);
}

void    ft_run(char *str, char *charset, char ***res)
{
    int i;
    int c;
    int len;

    i = 0;
    c = 0;
    len = 0;
    while (str[i])
    {
        if (mask_cins(str[i], charset))
        {
            if (len > 0)
                (*res)[c++] = ft_strndup(str + i - len, len);
            len = 0;
        }
        else
            len++;
        i++;
    }
    if (len > 0)
        (*res)[c++] = ft_strndup(str + i - len, len);
    (*res)[c] = NULL;
}

char **ft_split(char *str, char *charset)
{
    char **res;
    unsigned int    res_count;

    if (!str || !(*str))
        return (NULL);
    res_count = find_split_count(str, charset);
    if (res_count <= 1)
        return (NULL);
    res = malloc(sizeof(char *) * (res_count));
    if (!res)
        return (NULL);
    ft_run(str, charset, &res);
    return(res);
}

#include <stdio.h>
// 辅助打印
void print_split(char **arr)
{
    if (!arr)
        printf("NULL\n");
    else {
        int i = 0;
        while (arr[i])
            printf("'%s' ", arr[i++]);
        printf("\n");
    }
}

void free_split(char **arr)
{
    if (!arr) return;
    int i = 0;
    while (arr[i]) free(arr[i++]);
    free(arr);
}

int main()
{
    // 极端边界用例
    struct { char *str; char *charset; char *desc; } tests[] = {
        {"", "", "Empty string with empty charset"},
        {"hello", "", "Single-word string with empty charset"},
        {",,hello,world,,", ",", "String with leading and trailing separators"},
        {"hello,,,,world", ",", "String with multiple consecutive separators"},
        {"aaabbbaaaccc", "ab", "String with repeated separators"},
        {"a,,b", ",", "Double comma"},
        {",a,", ",", "Comma at both ends"},
        {",,,", ",", "All commas"},
        {"abc", "abc", "Split by all letters (should return NULL)"},
        {NULL, NULL, NULL}
    };

    for (int i = 0; tests[i].desc; ++i) {
        printf("Test %d: %s\n", i+1, tests[i].desc);
        char **split = ft_split(tests[i].str, tests[i].charset);
        print_split(split);
        free_split(split);
    }
    return 0;
}