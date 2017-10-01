#include <iostream>
#include <vector>

using namespace std;

/**
 * 辗转相除法求公因数
 * @param m 第一个数
 * @param n 第二个数
 * @return @arg m 和 @arg n 的公因数
 */
unsigned gcd(unsigned m, unsigned n) {
    if (m == 0)
        return n;
    return gcd(n % m, m);
}

/**
 * 计算 @arg v中，能组成最简真分数的数对个数
 * @param v 输入序列
 * @return 计算结果
 */
unsigned count_proper_fraction(vector<unsigned> v) {
    unsigned ret = 0;
    // 直接暴力求出v中的没有公因数的每个数对
    for (auto it = v.begin(); it != v.end() - 1; ++it) {
        //从it + 1开始枚举，避免重复
        for (auto it2 = it + 1; it2 != v.end(); it2++) {
            if (gcd(*it, *it2) == 1)
                ++ret;
        }
    }
    return ret;
}

int main() {
    unsigned n;
    cin >> n;
    vector<unsigned> input;
    for (unsigned i = 0; i < n; ++i) {
        unsigned val;
        cin >> val;
        input.push_back(val);
    }
    cout << count_proper_fraction(input);
    return 0;
}
