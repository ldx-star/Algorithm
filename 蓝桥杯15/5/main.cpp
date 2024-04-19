//
// Created by ldx on 24-4-19.
//
#include<iostream>
#include<cstdio>
#include<climits>
typedef long long LL;
using namespace std;
const int N = 1000 + 10;
LL sum[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        sum[i] = sum[i-1] + a;
    }
    LL min_val = INT_MAX;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n;j++){
            for(int k = j + 1; k <= n; k++){
                for(int m = k + 1;m <= n; m++){
                    LL ans =abs( (sum[j] - sum[i-1]) - (sum[m] - sum[k-1]));
                    if(ans < min_val){
                        min_val = ans;
                    }
                }
            }
        }
    }
    cout << min_val;
    return 0;
}