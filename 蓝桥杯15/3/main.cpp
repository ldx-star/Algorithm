//
// Created by ldx on 24-4-19.
//
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int arr[N];
int ans[3];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    int max_ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || j == k || i == k)continue;
                int s = gcd(gcd(arr[i], arr[j]), arr[k]);
                if (max_ans < s) {
                    max_ans = s;
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                    ans[2] = arr[k];
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}