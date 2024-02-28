//
// Created by ldx on 24-2-26.
//
/// https://www.acwing.com/problem/content/1242/
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int N = 1e5 + 10;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long max_val = 0;
    int max_idx = 1;
    int d = 1;
    int layer = 1;
    long long sum = 0;
    int k = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        if (i - j >= d) {
            while (i != j) {
                j++;
            }
            if (max_val < sum) {
                max_val = sum;
                max_idx = layer;
            }
            layer++;
            sum = 0;
            d = 1 << ++k;
        }
        sum += a[i];
    }
    if (max_val < sum) {
        max_idx = layer;
    }
    cout << max_idx << endl;
    return 0;
}