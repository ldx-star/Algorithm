//
// Created by ldx on 24-2-22.
//
///https://www.acwing.com/problem/content/description/1217/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
int h[N],tr[N],sum[N],n;
int lowbit(int x){
    return x & -x;
}
void add(int u){
    for(int i = u ; i < N; i+=lowbit(i)){
        tr[i]++;
    }
}
int query(int u){
    int res = 0;
    for(int i = u ; i ; i -= lowbit(i)){
        res += tr[i];
    }
    return res;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d",&h[i]);
        h[i]++;
    }
    for(int i = 0; i < n; i++){
        sum[i] = query(N-1) - query(h[i]);
        add(h[i]);
    }
    memset(tr,0,sizeof tr);
    for(int i = n - 1; i >= 0; i--){
        sum[i] += query(h[i]-1);
        add(h[i]);
    }
    ll res = 0;
    for(int i = 0; i < n; i++){
        res += (ll)(1 + sum[i])*sum[i]/2;
    }
    cout << res;
    return 0;
}