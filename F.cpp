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

//互质组
vector <vector<unsigned>> groups;

/**
 * 将元素放入互质组内
 * @param n 要放入的元素
 */
void put_into_group(unsigned n) {
    //对每一个组
    for (auto &group:groups) {
        bool should_in_this_group = true;
        for (auto ele:group) {
            //如果有和输入不互质的数字
            if (gcd(ele, n) != 1) {
                //不该放入这一组
                should_in_this_group = false;
                break;
            }
        }
        //如果没有发现任何和输入互质的数字
        if (should_in_this_group) {
            //放入该组，直接返回
            group.push_back(n);
            return;
        }
    }
    //执行到此说明不能放入任何一组
    //单独放入一个新组
    vector<unsigned> new_group{n};
    groups.push_back(new_group);
}

int main() {
    unsigned n;
    cin >> n;
    for (unsigned i = 0; i < n; ++i) {
        unsigned val;
        cin >> val;
        put_into_group(val);
    }
    //直接输出组数即可
    cout << groups.size();
    return 0;
}
