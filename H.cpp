#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * 判断素数
 * @param n 要判断的数
 * @return 是素数返回true，否则返回false
 * @note 此题用naive的筛法反而会超时（我还没有试过线性时间的筛法）
 *       由于要判断数据量不大，使用此法相对较快
 */
bool is_prime(unsigned n) {
    if (n == 2 || n == 3)
        return true;
    //性质：素数都在6n的两侧
    if (n <= 1 || (n % 6 != 1 && n % 6 != 5)) {
        return false;
    }
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * 枚举所有组合
 * @param bg 序列的起始迭代器
 * @param ed 序列的超尾迭代器
 * @param k  取k项
 * @return   由每种组合的和组成的vector
 */
vector<unsigned> combinations(vector<unsigned>::iterator bg, vector<unsigned>::iterator ed, unsigned k) {
    vector<unsigned> result;
    if (k == 1) {
        for (auto it = bg; it != ed; ++it) {
            result.push_back(*it);
        }
    } else if (ed - bg == k) {
        result.push_back(accumulate(bg, ed, 0U));
    } else {
        for (auto it = bg; it != ed - k + 1; ++it) {
            for (auto vk_1:combinations(it + 1, ed, k - 1)) {
                result.push_back(*it + vk_1);
            }
        }
    }
    return result;
}

/**
 * 枚举vector中的所有组合
 * @param src 要被枚举的vector
 * @param k 取k项
 * @return 由每种组合的和组成的vector
 */
vector<unsigned> combinations(vector<unsigned> &src, unsigned k) {
    return combinations(src.begin(), src.end(), k);
}

int main() {
    unsigned n, k;
    vector<unsigned> v;
    cin >> n >> k;
    for (unsigned i = 0; i < n; ++i) {
        unsigned num;
        cin >> num;
        v.push_back(num);
    }
    auto r = combinations(v, k);
    unsigned result = 0;
    //对每种组合的和，判断是否是素数
    for (auto ele:r) {
        if (is_prime(ele))
            ++result;
    }
    cout << result;
    return 0;
}
