//
// Created by ldx on 24-2-22.
//
/// https://www.acwing.com/problem/content/1272/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;
const int N = 1e5+10;
struct Node{
    int l,r;
    int Max;
}tr[4*N];
int w[N];
void build(int u,int l,int r){
    if(l==r)tr[u] = {l,r,w[l]};
    else{
        tr[u] = {l,r};
        int mid = l + r >> 1;
        build(u << 1, l,mid);
        build(u << 1 | 1, mid + 1, r);
        tr[u].Max = max(tr[u << 1].Max, tr[u << 1 | 1].Max);
    }
}
int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].Max;
    int res = INT_MIN;
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l) res = max(res,query(u << 1,l,r));
    if(mid < r) res = max(res,query(u<< 1 | 1, l, r));
    return res;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n;i++){
        scanf("%d",&w[i]);
    }
    build(1,1,n);
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query(1,l,r));
    }
    return 0;
}