//
// Created by ldx on 24-4-8.
//
///https://www.acwing.com/problem/content/852/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N  = 1.5e5 + 10;
int dist[N];
bool st[N];
int n,m;
struct Edge{
    int id,w;
};
vector<Edge> g[N];

int Dijkstra(){
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size()){
        int t = heap.top().second;
        heap.pop();
        if(st[t])continue;
        st[t] = true;
        for(int j = 0; j < g[t].size(); j++){
            int id = g[t][j].id;
            int w = g[t][j].w;
            dist[id] = min(dist[id], dist[t] + w);
            heap.push({dist[id],id});
        }
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}
int main(){
    cin >> n >> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
    }
    memset(dist,0x3f3f3f3f,sizeof dist);
    int res = Dijkstra();
    cout << res;
    return 0;
}