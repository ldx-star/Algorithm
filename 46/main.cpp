//
// Created by ldx on 24-4-18.
//
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510;
struct Edge{
    int id,w;
};
vector<Edge> g[N];
int dist[N];
int n,m;
bool st[N];

void Dijkstra(){
    memset(dist,0x3f3f3f3f,sizeof dist);
    dist[1] = 0;
    for(int i = 1; i <= n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(st[j]) continue;
            if(t == -1 || dist[t] > dist[j] ){
                t = j;
            }
        }
        st[t] = true;
        for(int i = 0; i < g[t].size(); i++){
            int id = g[t][i].id;
            dist[id] = min(dist[id], dist[t] + g[t][i].w);
        }
    }
    if(dist[n] == 0x3f3f3f3f){
        cout << -1;
    }else{
        cout << dist[n];
    }

}

int main(){

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        g[a].push_back({b,w});
    }
    Dijkstra();

    return 0;
}