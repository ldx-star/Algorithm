//
// Created by ldx on 24-4-18.
//
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
const int N =1.5e5+10;
struct Edge {
    int id, w;
};
vector <Edge> g[N];
typedef pair<int, int> PII;
priority_queue <PII, vector<PII>, greater<>> heap;
int dist[N];
int n, m;
bool st[N];


void Dijkstra() {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[1] = 0;
    heap.push({0, 1});
    while(!heap.empty()){
        auto t = heap.top().second;
        heap.pop();
        if(st[t])continue;
        st[t] = true;
        for (int i = 0; i < g[t].size(); i++) {
            int id = g[t][i].id;
            dist[id] = min(dist[id], dist[t] + g[t][i].w);
            heap.push({dist[id], id});
        }
    }

    if (dist[n] == 0x3f3f3f3f) {
        cout << -1;
    } else {
        cout << dist[n];
    }
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a].push_back({b, w});
    }
    Dijkstra();

    return 0;
}