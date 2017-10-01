#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * 解有三个实数解的一元三次方程
 * @param a 三次项系数
 * @param b 二次项系数
 * @param c 一次项系数
 * @param d 常数项
 * @return 存放在vector内的三个解，按从小到达排序
 */
std::vector<double> solve(double a, double b, double c, double d) {
    double A = b * b - 3 * a * c;
    double B = b * c - 9 * a * d;
    double C = c * c - 3 * b * d;
    double delta = b * b - 4 * a * c;
    //题目里说了有三个不同实根，故Δ=B^2－4AC<0
    double T = (2 * A * b - 3 * a * B) / (2 * A * sqrt(A));
    double theta = acos(T);
    double x1 = (-b - 2 * sqrt(A) * cos(theta / 3)) / (3 * a);
    double x2 = (-b + sqrt(A) * (cos(theta / 3) + sqrt(3) * sin(theta / 3))) / (3 * a);
    double x3 = (-b + sqrt(A) * (cos(theta / 3) - sqrt(3) * sin(theta / 3))) / (3 * a);
    vector<double> result{x1, x2, x3};
    sort(result.begin(), result.end());
    return result;
}

int main() {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    auto result = solve(a, b, c, d);
    printf("%.2f %.2f %.2f", result[0], result[1], result[2]);
    return 0;
}


