//
// Created by ldx on 24-4-15.
//
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e6+10;
PII a[N];
int idx = 0;
int digit(int x){
    int res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    return res;
}
int main() {
    // 请在此输入您的代码
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int dig = digit(i);
        a[idx++] = {dig,i};
    }
    sort(a,a+idx);
    cout << a[m-1].second << endl;
    return 0;
}