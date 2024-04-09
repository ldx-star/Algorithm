#include <iostream>
using namespace std;
typedef long long LL;
int n;

LL C(int a,int b){
    LL res = 1;
    for(int i = a, j = 1; j <= b; i--, j++){
        res = res * i / j;
        if(res > n) return res;
    }
    return res;
}

bool check(int k){
    LL l = 2 * k,r = n;
    if(l > r) return false;
    // 找小于等于n的第一个数
    while(l < r){
        int mid = l + r>> 1;
        if(C(mid,k) >= n) r = mid;
        else l = mid + 1;
    }
    if(C(r,k) != n) return false;
    else {
        cout << (1 + r) * r / 2 + k + 1;
    }
    return true;
}
int main()
{
    // 请在此输入您的代码
    cin >> n;
    for(int i = 16; ; i--){
        if(check(i)) break;
    }
    return 0;

}