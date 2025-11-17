#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (count < n && src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	while (count < n)
	{
		dest[count] = '\0';
		count++;
	}
	return (dest);
}

char    *ft_insert_str(char *src, int len)
{
    char *dest;

    dest = malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (NULL);
    ft_strncpy(dest, src, len);
    dest[len] = '\0';

    return (dest);
}

int    ft_char_in(char str, char *charset)
{
	unsigned char mask[32] = {0};
    unsigned char c;
	
    while (*charset)
    {
        c = (unsigned char)*charset;
        mask[c / 8] = (mask[c / 8]) | (1U << (c % 8));
        charset++;
    }
    
    c = (unsigned char)str;
    if ((mask[c / 8]) & (1U << (c % 8)))
        return (1);
    return (0);
}

int    ft_run(char *str, char *charset, char ***res_str, int *count)
{
    int l;
    int r;

    l = 0;
    r = 0;
    while (str[l + r])
    {
        if (ft_char_in(*(str + l + r), charset) == 1)
        {
            if (r > 0)
                (*res_str)[(*count)++] = ft_insert_str(str + l, r);
            l = l + r + 1;
            r = 0;
        }
        else
            r++;
    }
    if (r > 0)
        (*res_str)[(*count)++] = ft_insert_str(str + l, r);
    (*res_str)[(*count)] = NULL;
    return (*count);
}

char **ft_split(char *str, char *charset)
{
    char    **res_str;
	unsigned int	i;
    int count;

    if (!str || !(*str))
        return (NULL);    
	i = 0;
	while (str[i])
		i++;
    res_str = malloc(sizeof(*res_str) * (i + 2));
    if (!charset || !(*charset))
    {
        res_str[0] = ft_insert_str(str, i);
        res_str[1] = NULL;
        return res_str;
    }
    count = 0;
    if (ft_run(str, charset, &res_str, &count) == 0)
        return (NULL);
    return res_str;
}

// #include <stdio.h>
// int main()
// {
//     char *str = "time, is, money, money, is, catnip";
//     // char *str = "time, is, catnip";
//     // char **split_str = ft_split(str, "money");
//     char **split_str = ft_split(str, ", ");

//     int i = 0;
//     while (split_str[i])
//     {
//         printf("%s\n", split_str[i]);
//         i++;
//     }    

//     return (0);
// }

// int main(void)
// {
//     char *tests[] = {
//         "time, is, money, money, is, catnip",
//         "catnip",
//         "",
//         ", ",
//         "a, ,b, ,c",
//         "  ,  ,  ",
//         "one,,two,,three",
//         NULL
//     };

//     for (int t = 0; tests[t]; t++) {
//         printf("Test %d: \"%s\"\n", t, tests[t]);
//         char **split_str = ft_split(tests[t], ", ");
//         int i = 0;
//         while (split_str && split_str[i]) {
//             printf("[%d] '%s'\n", i, split_str[i]);
//             free(split_str[i]);
//             i++;
//         }
//         free(split_str);
//         printf("----\n");
//     }

//     return 0;
// }


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