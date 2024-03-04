/// https://www.acwing.com/problem/content/1298/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 50000;
int primes[N],cnt = 0;
int st[N];
int ans[N],len = 0;

bool is_prime(int n){
    if(n < N) return !st[n];
    for(int i = 0; primes[i] <= n / primes[i]; i++){
        if(n % primes[i] == 0) return false;
    }
    return true;
}

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void dfs(int last,int prod,int s){
    if(s == 1){
        ans[len++] = prod;
        return;
    }
    if(s - 1 > (last < 0 ? 1 : primes[last]) && is_prime(s - 1)){
        ans[len++] = prod * (s - 1);
    }
    for(int i = last + 1; primes[i] <= s / primes[i]; i++){
        int p = primes[i];
        for(int j = 1 + p,t = p;j <= s; t *= p, j += t){
            if(s % j == 0) dfs(i, prod * t, s / j);
        }
    }

}

int main(){
    get_primes(N);
    int s;
    while(cin >> s){
        len = 0;
        dfs(-1,1,s);
        cout << len << endl;
        if(len){
            sort(ans, ans + len);
            for(int i = 0; i < len; i++){
                cout << ans[i] << " ";
            }
            puts("");
        }

    }

    return 0;
}