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
    if (m == 0) return n;
    return gcd(n % m, m);
}

/**
 * 计算 @arg v中，一个数是另一个的两倍的数对个数
 * @param v 输入序列
 * @return 计算结果
 */
unsigned count_is_double(vector<unsigned> v) {
    unsigned ret = 0;
    // 直接暴力求出v中每一个数对
    for (auto it = v.begin(); it != v.end(); ++it) {
        for (auto it2 = v.begin(); it2 != v.end(); it2++) {
            if (*it2 == 2 * (*it)) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    unsigned input_val;
    vector<unsigned> input;
    while (cin >> input_val) {
        if (input_val == 0U)        //输入0即跳出循环
            break;
        input.push_back(input_val);
    }
    cout << count_is_double(input);
    return 0;
}
