#include <iostream>
#include <map>

using namespace std;
// 缓存计算结果，避免重复计算
map<unsigned, map<unsigned, unsigned> > buffer;

/**
 * 将一个数用小于等于@arg less_than 的数分拆的种数
 * @param n 要分拆的数
 * @param less_than 分拆时使用的数的最大值 <= @arg less_than
 * @return 计算结果
 * @example divide_count(4, 2):
 * 4 = 4        <- 分拆时使用了大于2的数字，不会计入
 * 4 = 3 + 1    <- 分拆时使用了大于2的数字，不会计入
 * 4 = 2 + 2
 * 4 = 2 + 1 + 1
 * 4 = 1 + 1 + 1 + 1
 * 故返回3
 */
unsigned divide_count(unsigned n, unsigned less_than) {
    // 分拆时使用的数的最大值 大于等于 这个数本身，没有意义
    if (less_than > n)
        less_than = n; //设置为这个数本身
    // 1只有1种分拆
    // 任何数字用<=1的数字分拆（即用1分拆）只有一种分拆方式
    if (n == 1 || less_than == 1) {
        return 1;
    }
    // 缓存中有，直接取缓存中的值
    if (buffer.find(n) != buffer.end() && buffer[n].find(less_than) != buffer[n].end()) {
        return buffer[n][less_than];
    }
    // 如果分拆时使用的数的最大值 等于 这个数本身，那么"这个数本身"就是一种合理的分拆
    if (n == less_than)
        buffer[n][less_than] = 1;
    // 先分拆出1个 <= less_than的数，再对剩下的数进行分拆
    // 结果就是这些"剩下的数进行分拆"的结果的总和
    for (unsigned i = 1; i <= less_than; ++i)
        if (n - i != 0) //对0进行分拆没有意义
            buffer[n][less_than] += divide_count(n - i, i);
    return buffer[n][less_than];
}

int main() {
    unsigned n;
    while (cin >> n) {
        cout << divide_count(n, n) << endl;
    }
    return 0;
}


