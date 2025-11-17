#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char **ft_split(char *str, char *charset)
{
    char **result;
    int len;
    int count;
    char *charset_start;

    charset_start = charset;
    len = ft_strlen(str) + 1;
    result = malloc(sizeof(char *) * (len + 1));
    count = 0;
    while (len > count)
    {
        result[count] = malloc(sizeof(char) * ft_strlen(str));
        count++;
    }
    count = 0;
    while (*str)
    {
        *(result[count]) = *str;
        charset = charset_start;
        while (*charset)
        {
            if (*str == *charset)
            {
                *(result[count]) = '\0';
                count++;
                *(result[count]) = *charset;
                count++;
            }
            charset++;
        }
        str++;
    }
    result[count] = NULL;
    return (result);
}
