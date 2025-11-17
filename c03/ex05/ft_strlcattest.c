// test_strlcat.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int count;

	count = 0;
	while (size > 0 && *dest)
	{
		dest++;
		count++;
		size--;
	}
	while (size > 1 && *src)
	{
		*dest++ = *src++;
		count++;
		size--;
	}
	while (*src++)
		count++;
	if (size > 0)
		*dest = '\0';
	return (count);
}

// 参考实现（遵循 BSD 语义）
static size_t ref_strlcat(char *dst, const char *src, size_t size) {
    size_t dlen = strnlen(dst, size);
    size_t slen = strlen(src);
    if (dlen == size) {
        return size + slen;           // no room / no NUL within first size
    }
    if (size > dlen) {
        size_t space = size - dlen - 1;           // room excluding NUL
        size_t copy  = (slen < space) ? slen : space;
        if (copy > 0) memcpy(dst + dlen, src, copy);
        dst[dlen + copy] = '\0';
    }
    return dlen + slen;
}

typedef enum { INIT_STR, INIT_NO_NUL_PREFIX } init_mode;

// 初始化 dest：
// INIT_STR：按字符串拷贝
// INIT_NO_NUL_PREFIX：在前 size 个字节内不放 NUL（测试 dlen==size 情形）
static void init_dest(char *buf, size_t cap, init_mode mode,
                      const char *s, size_t size_for_prefix) {
    // 先清成 0xAA 方便肉眼看越界（打印不显示）
    memset(buf, 0xAA, cap);
    if (mode == INIT_STR) {
        // 正常字符串
        size_t n = strlen(s);
        if (n >= cap) n = cap - 1;
        memcpy(buf, s, n);
        buf[n] = '\0';
    } else {
        // 前 size_for_prefix 个字节都不是 NUL
        size_t fill = (size_for_prefix < cap ? size_for_prefix : cap);
        memset(buf, 'A', fill);
        // 在更后面再放一个 NUL，保证整个缓冲总体还是个以 NUL 结尾的区域
        if (fill + 2 < cap) {
            buf[fill + 1] = 'B';
            buf[fill + 2] = '\0';
        } else if (cap > 0) {
            buf[cap - 1] = '\0';
        }
    }
}

static void hexdump(const unsigned char *p, size_t n) {
    for (size_t i = 0; i < n; i++) printf("%02X ", p[i]);
}

static void run_case(const char *name,
                     init_mode mode,
                     const char *dest_init,
                     const char *src,
                     size_t cap,        // 实际分配的缓冲区大小
                     size_t size_arg)   // 传给 *strlcat 的 size
{
    // 分配两份缓冲：一份给你的实现，一份给参考实现
    char *u = (char*)malloc(cap);
    char *r = (char*)malloc(cap);
    if (!u || !r) { fprintf(stderr, "alloc fail\n"); exit(1); }

    init_dest(u, cap, mode, dest_init, size_arg);
    init_dest(r, cap, mode, dest_init, size_arg);

    // 运行
    unsigned int ret_u = ft_strlcat(u, src, (unsigned int)size_arg);
    size_t       ret_r = ref_strlcat(r, src, size_arg);

    // 判等
    int same_ret = ((size_t)ret_u == ret_r);
    int same_buf = (strcmp(u, r) == 0);

    // 输出
    printf("== %s ==\n", name);
    printf("  src=\"%s\"  cap=%zu  size=%zu\n", src, cap, size_arg);
    printf("  ret_u=%u  ret_ref=%zu  %s\n",
           ret_u, ret_r, same_ret ? "RET:PASS" : "RET:FAIL");
    printf("  dst_u=\"%s\"\n", u);
    printf("  dst_r=\"%s\"  %s\n", r, same_buf ? "BUF:PASS" : "BUF:FAIL");

    // 额外：看一眼前 size+4 字节的十六进制，辅助观察是否越界写
    size_t probe = (size_arg + 4 <= cap) ? (size_arg + 4) : cap;
    printf("  [hex u 0..%zu): ", probe); hexdump((unsigned char*)u, probe); puts("");
    printf("  [hex r 0..%zu): ", probe); hexdump((unsigned char*)r, probe); puts("");
    puts("");

    free(u); free(r);
}

int main(void) {
    // 用例列表（覆盖 size==0、size<=dlen、刚好1格、完整拼接、src为空、前size无NUL 等）
    run_case("A: size==0",           INIT_STR,         "hi",     "XYZ",   32, 0);
    run_case("B: size==1",           INIT_STR,         "",       "XYZ",   32, 1);
    run_case("C: size<dlen",         INIT_STR,         "abc",    "XYZ",   32, 2);
    run_case("D: size==dlen+1",      INIT_STR,         "abc",    "XYZ",   32, 4);
    run_case("E: partial append",    INIT_STR,         "abc",    "XYZ",   32, 5);
    run_case("F: full append",       INIT_STR,         "abc",    "XYZ",   32, 7);
    run_case("G: src empty",         INIT_STR,         "abcd",   "",      32, 5);
    run_case("H: no NUL in prefix",  INIT_NO_NUL_PREFIX, NULL,   "XYZ",   32, 5);

    return 0;
}
