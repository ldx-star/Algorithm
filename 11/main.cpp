//
// Created by ldx on 24-2-22.
//
///https://www.acwing.com/problem/content/description/1226/
#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
const int N = 1e4 + 10;
int a[N];
bool st[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            k++;
            int j = i;
            while (!st[j]) {
                st[j] = true;
                j = a[j];
            }
        }

    }
    cout << n - k;
    return 0;
}