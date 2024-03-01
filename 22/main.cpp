/// https://www.acwing.com/problem/content/1241/

#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
const int mod = 1000000009;
int a[N];

int main(){
    int n,k;
    LL res = 1;
    cin >> n >> k;
    int sign = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0)sign++;
    }
    if(n == k){
        for(int i = 0; i < n; i++){
            res = res * a[i] % mod;
        }
    }else {
        sort(a,a+n);
        if(k % 2 == 0){
            int i = 0, j = n - 1;
            while(k){
                LL tmp1 = (LL)a[i] * a[i + 1];
                LL tmp2 = (LL)a[j] * a[j - 1];
                if(tmp1 > tmp2){
                    i += 2;
                    res = res * (tmp1 % mod) % mod;
                }else{
                    j -= 2;
                    res = res * (tmp2 % mod) % mod;
                }
                k -= 2;
            }
        }else{
            if(sign == n){
                int j = n - 1;
                while(k){
                    res = res * a[j] % mod;
                    j--;
                    k--;
                }
            }else{
                int i = 0,j = n - 1;
                res = res * a[j] % mod;
                k--,j--;
                while(k){
                    LL tmp1 = (LL)a[i] * a[i + 1];
                    LL tmp2 = (LL)a[j] * a[j - 1];
                    if(tmp1 > tmp2){
                        i += 2;
                        res = res * (tmp1 % mod) % mod;
                    }else{
                        j -= 2;
                        res = res * (tmp2 % mod) % mod;
                    }
                    k -= 2;
                }
            }
        }
    }
    cout << res;
    return 0;
}