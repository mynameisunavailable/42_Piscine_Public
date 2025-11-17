#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

typedef struct {
    const char *name;
    const char *nbr;
    const char *base_from;
    const char *base_to;
    const char *expected;  // 期望字符串；若期望为 NULL，则写成 "(NULL)"
} T;

// static int eq_nullable(const char *a, const char *b) {
//     if (a == NULL && b == NULL) return 1;
//     if (a == NULL || b == NULL) return 0;
//     return strcmp(a, b) == 0;
// }

int main(void) {
    T cases[] = {
        // 基本正确性
        {"dec->bin_zero",           "0", "0123456789", "01", "0"},
        {"dec->hex_pos",            "255", "0123456789", "0123456789ABCDEF", "FF"},
        {"dec->hex_neg",            "-42", "0123456789", "0123456789ABCDEF", "-2A"},
        {"hex->dec",                "7fffffff", "0123456789abcdef", "0123456789", "2147483647"},
        {"bin->dec",                "101010", "01", "0123456789", "42"},
        {"leading_zeros",           "00000123", "0123456789", "01234567", "173"},

        // 空白与符号处理
        {"ws_and_signs_1",          "  \t\n--+-+214", "0123456789", "01", "-11010110"},
        {"only_ws_and_signs",       "   +--+-  ", "0123456789", "0123456789", "0"},
        {"leading_ws_hex",          " \v \t 1f", "0123456789abcdef", "0123456789", "31"},

        // 非法字符终止（解析前缀）
        {"prefix_only_bin",         "10102", "01", "0123456789", "10"}, // 只解析 "1010"
        {"prefix_only_hex",         "2G", "0123456789ABCDEF", "0123456789", "2"},

        // base 校验（无效 base -> 返回 NULL）
        {"invalid_base_dup",        "1010", "001", "0123456789", "(NULL)"},
        {"invalid_base_plus",       "123", "012+3456789", "01", "(NULL)"},
        {"invalid_base_space",      "123", "0123 456789", "01", "(NULL)"},
        {"invalid_base_len1",       "5", "0", "0123456789", "(NULL)"},
        {"invalid_base_to_dup",     "10", "0123456789", "00", "(NULL)"},
        {"invalid_base_to_ws",      "10", "0123456789", "0 1", "(NULL)"},

        // 越界（超出 32-bit int）——应返回 NULL
        {"overflow_pos",            "2147483648", "0123456789", "01", "(NULL)"},
        {"overflow_neg",            "-2147483649", "0123456789", "01", "(NULL)"},

        // 边界值
        {"int_max_to_hex",          "2147483647", "0123456789", "0123456789abcdef", "7fffffff"},
        {"int_min_to_hex",          "-2147483648", "0123456789", "0123456789ABCDEF", "-80000000"},
        {"int_min_to_bin",          "-2147483648", "0123456789", "01",
         "-10000000000000000000000000000000"}, // 1+31个0

        // 空串 & 只有符号
        {"empty_string",            "", "0123456789", "0123456789", "0"},
        {"only_sign",               "----", "0123456789", "0123456789", "0"},

        // base_from/base_to 使用非数字字符集
        // {"alpha_base",              "cab", "abc", "0123456789", "5"}, // c(2)*3 + a(0)*1 + b(1)= 2*3+0+1=7? (错误示例检查)
        // 更正：若 base="abc"(3进制)，"cab"= c(2)*3^2 + a(0)*3 + b(1) = 2*9 + 0 + 1 = 19(dec)
        // 为了自动核对，此处改为期望 "19"
        {"alpha_base_fixed",        "cab", "abc", "0123456789", "19"},

        // 非 ascii / 符号型 base（只要满足规则就允许）
        // {"sym_base",                "@!@!", "@!", "0123456789", "3"}, // "@!@!" = 0,1,0,1 -> 0*2^3+1*2^2+0*2+1=5？再核：@=0, !=1 => 0101b=5
        // 修正：0101b = 5
        {"sym_base_fixed",          "@!@!", "@!", "0123456789", "5"},
    };

    int n = (int)(sizeof(cases)/sizeof(cases[0]));
    int pass = 0, fail = 0;

    for (int i = 0; i < n; ++i) {
        const char *exp = cases[i].expected;
        char *got = ft_convert_base((char*)cases[i].nbr, (char*)cases[i].base_from, (char*)cases[i].base_to);

        int ok = 0;
        if (strcmp(exp, "(NULL)") == 0) ok = (got == NULL);
        else                            ok = (got != NULL && strcmp(got, exp) == 0);

        printf("[%02d] %-22s : %s\n", i+1, cases[i].name, ok ? "OK" : "FAIL");
        if (!ok) {
            printf("     nbr=\"%s\" from=\"%s\" to=\"%s\"\n",
                cases[i].nbr, cases[i].base_from, cases[i].base_to);
            printf("     expected: %s\n", exp);
            printf("     got     : %s\n", got ? got : "(NULL)");
        }
        if (got) free(got); // 你的实现应返回堆内存
        pass += ok; fail += !ok;
    }

    printf("\nSummary: %d / %d passed, %d failed.\n", pass, n, fail);
    return fail ? 1 : 0;
}