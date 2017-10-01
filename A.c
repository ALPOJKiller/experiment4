#include <stdio.h>

//缓存计算结果，避免重复计算
unsigned long long buffer[31];

/**
 * 计算到达第n级的方法数
 * @param n 级数
 * @return 计算结果
 * @note 由于第 @arg n 级台阶可以
 * 由第n-1级台阶走1级 或者
 * 由第n-2级台阶走2级
 * 故f(n) = f(n-1) + f(n-2)
 */
unsigned long long f(unsigned n) {
    //第一第二级台阶作为递归终止条件
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    if (buffer[n] == -1) {
        buffer[n] = f(n - 1) + f(n - 2);
    }
    return buffer[n];
}

int main(void) {
    //初始化缓存为空
    for (unsigned i = 0; i < 31; ++i)
        buffer[i] = -1;
    unsigned i;
    //读取并计算，直到遇到文件尾
    while (scanf("%u", &i) != EOF) {
        printf("%llu\n", f(i));
    }
    return 0;
}
