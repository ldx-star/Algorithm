///https://www.acwing.com/problem/content/1080/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 2e5+10;
vector<int> h[N];
int d1[N],d2[N],p[N],up[N];
int maxd = 0;
void dfs_d(int u,int parent){
    for(auto e : h[u]){
        if(e != parent){
            dfs_d(e,u);
            int distance = d1[e] + 1;
            if(distance > d1[u]){
                d2[u] = d1[u];
                d1[u] = distance;
                p[u] = e;
            }else if(distance > d2[u]){
                d2[u] = distance;
            }
        }
    }
    maxd = max(maxd,d1[u] + d2[u]);
}
void dfs_u(int u, int parent){
    for(auto e : h[u]){
        if(e != parent){
            up[e] = up[u] + 1;
            if(p[u] == e) up[e] = max(up[e],d2[u]+1);
            else{
                up[e] = max(up[e],d1[u]+1);
            }
            dfs_u(e,u);
        }
    }
}
int main(){
    int n;
    cin >> n;
    int u = 0;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        h[a].push_back(b);
        h[b].push_back(a);
    }
    dfs_d(u,-1);
    dfs_u(u,-1);
    for(int i = 0; i < n; i++){
        int tmp[3] = {d1[i],d2[i],up[i]};
        sort(tmp,tmp + 3);
        int ret = tmp[1] + tmp[2];
        if(ret == maxd)cout << i << endl;
    }
    return  0;
}