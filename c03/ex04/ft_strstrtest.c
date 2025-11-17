#include <stdio.h>
#include <string.h>

char *ft_strstr(char *str, char *to_find); // 你的实现声明

static long idx_from(const char *hay, const char *res) {
    return res ? (long)(res - hay) : -1;
}

static void run(const char *hay, const char *needle) {
    char *std_res = strstr(hay, needle);
    char *ft_res  = ft_strstr((char*)hay, (char*)needle);
    long i_std = idx_from(hay, std_res);
    long i_ft  = idx_from(hay, ft_res);
    printf("hay=\"%s\" needle=\"%s\" | strstr=%ld ft=%ld%s\n",
           hay, needle, i_std, i_ft, (i_std==i_ft ? "" : "  <-- mismatch"));
}

int main(void) {
    run("", "");
    run("", "a");
    run("a", "");
    run("abc", "");
    run("abc", "a");
    run("abc", "bc");
    run("abcd", "cd");
    run("abcd", "abcd");
    run("abcd", "abcde");
    run("aaaa", "aa");
    run("mississippi", "issi");
    run("abc", "x");
    run("Abc", "abc");
    return 0;
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