//
// Created by ldx on 24-4-18.
//
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int a[N];
LL sum[N];
int n,x;
bool check(int m){
    for(int l = 1; l + m - 1 < n; l++){
        int r = l + + m - 1;
        if((sum[r] - sum[l-1]) < x) return false;
    }
    return true;
}

int main() {
    // 请在此输入您的代码
    cin >> n >> x;
    x *= 2;
    for (int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        sum[i] = a[i] + sum[i - 1];
    }
    int l = 1, r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;

    return 0;
}