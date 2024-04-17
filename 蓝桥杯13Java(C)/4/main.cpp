//
// Created by ldx on 24-4-15.
//
#include <iostream>

using namespace std;
typedef long long LL;
int digit[10];
int main() {
    // 请在此输入您的代码
    for (LL i = 1; i <= 20230408; i++) {
        LL tmp = i;
        while (tmp) {
            digit[tmp % 10]++;
            tmp /= 10;
        }
    }
    LL sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += (i * digit[i]);
    }
    cout << sum;
    return 0;
}