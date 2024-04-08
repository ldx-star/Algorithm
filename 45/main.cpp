//
// Created by ldx on 24-4-8.
//
///https://www.acwing.com/problem/content/855/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e4+10;
struct Edge{
    int a,b,w;
}edges[N];
int dist[N];
int backup[N];
int n,m,k;

int Bellman_Ford(){
    memset(dist, 0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < k ;i++){
        memcpy(backup,dist,sizeof dist);
        for(int j = 0; j < m; j++){
            int a = edges[j].a;
            int b = edges[j].b;
            int w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if(dist[n] >= 0x3f3f3f3f / 2){
        cout << "impossible";
    }else{
        cout << dist[n]<< endl;
    }

}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges[i] = {a,b,w};
    }

    Bellman_Ford();

    return 0;
}