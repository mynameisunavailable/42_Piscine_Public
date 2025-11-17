#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep);

static void check(const char *name, char *got, const char *expect) {
    if (!got) {
        printf("[FAIL] %s: got NULL\n", name);
        exit(1);
    }
    if (strcmp(got, expect) != 0) {
        printf("[FAIL] %s\n  expect: \"%s\" (len %zu)\n  got   : \"%s\" (len %zu)\n",
               name, expect, strlen(expect), got, strlen(got));
        free(got);
        exit(1);
    }
    printf("[OK] %s\n", name);
    free(got);
}

int main(void) {
    puts("=== start tester ===");

    // 基础：size == 0
    {
        char *arr[] = {"x","y"};
        check("size=0, sep=': ;'", ft_strjoin(0, arr, ": ;"), "");
        check("size=0, sep=''",    ft_strjoin(0, arr, ""),      "");
    }

    // 你的设计：sep == NULL → 返回空串（非题面，但符合你实现）
    {
        char *arr[] = {"x","y"};
        check("size=0, sep=NULL (your design)", ft_strjoin(0, arr, NULL), "");
    }

    // size == 1（不应追加分隔符）
    {
        char *arr[] = {"abc"};
        check("size=1, sep=':'", ft_strjoin(1, arr, ":"), "abc");
    }

    // 常规多元素
    {
        char *arr[] = {"cat","nip","time"};
        check("3 strs, sep=': ;'", ft_strjoin(3, arr, ": ;"), "cat: ;nip: ;time");
        check("3 strs, sep=''",    ft_strjoin(3, arr, ""),     "catniptime");
    }

    // 含空串
    {
        char *arr1[] = {"",""};
        check("['',''], sep='X'", ft_strjoin(2, arr1, "X"), "X");

        char *arr2[] = {"","a",""};
        check("['','a',''], sep='-'", ft_strjoin(3, arr2, "-"), "-a-");
    }

    // 长分隔符
    {
        char *arr[] = {"A","B","C","D"};
        check("4 strs, long sep", ft_strjoin(4, arr, "--SEP--"), "A--SEP--B--SEP--C--SEP--D");
    }

    // 你的设计：数组里含 NULL 元素 → 返回空串
    {
        char *arr[] = {"head", NULL, "tail"};
        check("strs contains NULL (your design)", ft_strjoin(3, arr, ":"), "");
    }

    // 你的设计：strs == NULL（整体为 NULL） → 返回空串
    {
        char **arr = NULL;
        check("strs == NULL (your design)", ft_strjoin(2, arr, ":"), "");
    }

    puts("\nAll tests passed ✓");
    return 0;
}
