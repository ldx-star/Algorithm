///https://www.lanqiao.cn/paper/3830/problem/1452/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2022;
struct Edge {
    int id, w;
};
vector<Edge> g[N];
bool st[N];
int dist[N];


int get_gcd(int a, int b) {
    return b ? get_gcd(b, a % b) : a;
}

int get_weight(int a, int b) {
    int gcd = get_gcd(a, b);
    return a * b / gcd;
}

void Dijkstra(int start) {
    dist[start] = 0;
    for (int i = start; i < N; i++) {
        int t = -1;
        for (int j = 1; j < N ; j++) {
            if(st[j])continue;
            if(t== -1 || dist[t] > dist[j]){
                t = j;
            }
        }
        st[t] = true;
        for(int j = 0; j < g[t].size(); j++){
            int id = g[t][j].id;
            dist[id] = min(dist[t] + g[t][j].w,dist[id]);
        }
    }
}

int main() {
    // 请在此输入您的代码
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (i != j && abs(i - j) <= 21) {
                int w = get_weight(i, j);
                g[i].push_back({j, w});
            }
        }
    }

    memset(dist, 0x3f3f3f3f, sizeof dist);
    Dijkstra(1);
    cout << dist[2021];
    return 0;
}
