#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0)
	{
		if ((*s1 != *s2) || (*s1 == '\0'))
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	char *str_temp;
	char *to_find_temp;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		str_temp = str;
		to_find_temp = to_find;
		while ((*str_temp == *to_find_temp) && *str_temp)
		{
			str_temp++;
			to_find_temp++;
		}
		if (*to_find_temp == '\0')
			return (str);
		str++;
	}
	return (NULL);
}