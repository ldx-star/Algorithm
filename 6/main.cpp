//
// Created by ldx on 24-2-22.
//
///https://www.acwing.com/problem/content/1230/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e4+10;
struct Segment{
    int x,y1,y2;
    int k;
    bool operator<(const Segment& s)const{
        return x < s.x;
    }
}seg[2*N];
struct Node{
    int l,r;
    int cnt,len;
}tr[N*4];
void build(int u,int l,int r){
    tr[u] = {l,r};
    if(l == r)return;
    int mid = l + r >> 1;
    build(u << 1,l,mid);
    build(u << 1 | 1,mid+1, r);
}
void pushup(int u){
    if(tr[u].cnt > 0) tr[u].len = tr[u].r - tr[u].l + 1;
    else if(tr[u].l==tr[u].r) tr[u].len = 0;
    else tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
}
void modify(int u,int l,int r,int k){
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].cnt += k;
        pushup(u);
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l) modify(u << 1, l,r,k);
        if(mid < r)modify(u << 1 | 1, l, r, k);
        pushup(u);
    }

}
int main(){
    int n;
    cin >> n;
    int m = 0;
    for(int i = 0; i < n; i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        seg[m++] = {x1,y1,y2,1};
        seg[m++] = {x2,y1,y2,-1};
    }
    sort(seg,seg+m);
    build(1,0,10000);
    int res = 0;
    for(int i = 0; i < m; i++){
        if(i > 0) res += tr[1].len * (seg[i].x-seg[i-1].x);
        modify(1,seg[i].y1,seg[i].y2-1,seg[i].k);
    }
    cout << res;
    return 0;
}