//
// Created by ldx on 24-2-22.
//
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PLL;
const int N = 1e6 + 10;
PLL a[N];
PLL tr[N];

int lowbit(int x){
    return x&-x;
}
void add(int u){
    int x = ++tr[u].first;
    for(int i = u; i <= N;i+=lowbit(i)){
        tr[i].second+=x;
    }
}
int query(int u){
    int res = 0;
    for(int i = u; i; i -= lowbit(i)){
        res += tr[i].second;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i].first = i;
        a[i].second = x;
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (a[j].second > a[j + 1].second) {
                swap(a[j], a[j + 1]);
                add(a[j].first);
                add(a[j+1].first);
                flag = true;
            }
        }
        if(flag){
            flag = false;
        }else{
            break;
        }
    }

    cout << query(N-1);
    return 0;
}