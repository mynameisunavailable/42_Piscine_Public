#include <stdio.h>
//checks the s1 string for duplicate of char c
int ft_check_duplicate_char(char c, char *s1)
{
    // int count = 0;
    while (*s1)
    {
        // return (printf("%c, %c\n", c, s1[0]));
        if (c == s1[0])
        {
            return (1);
        }
        s1++;
    }
    return (0);
}

int main ()
{
    char *start = "string";
    char *bing = "11kdlso";
    char chara;

    // while (*start)
    // {
    //     chara = *start;
    //     if (ft_check_duplicate_char(chara, start + 1) == 1)
    //         return (printf("found"));
    //     // if (chara == *start + 1)
    //     //     return (printf("found"))
    //     start++;
    // }
    // return (printf("not found"));
    
    while (*bing)
    {
        chara = *bing;
        if (ft_check_duplicate_char(chara, bing + 1) == 1)
            return (printf("found"));
        // if (chara == *bing + 1)
        //     return (printf("found"))
        bing++;
    }
    return (printf("not found"));
}