/// https://www.acwing.com/problem/content/1209/
#include<iostream>
#include<vector>
using namespace std;

struct Edge{
    int id,w;
};

const int N = 1e5+10;
vector<Edge> h[N];
int dist[N];

void dfs(int u,int father,int d){
    dist[u] = d;
    for(auto e : h[u]){
        if(e.id != father){
            dfs(e.id,u,d + e.w);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int u = 1;
    for(int i = 0; i < n-1; i++){
        int a,b,c;
        cin >> a >> b >> c;
        h[a].push_back({b,c});
        h[b].push_back({a,c});
    }
    dfs(u,-1,0);
    for(int i = 1; i <= n; i++){
        if(dist[u] < dist[i]){
            u = i;
        }
    }
    dfs(u,-1,0);
    u = 1;
    for(int i = 1; i <= n; i++){
        if(dist[u] < dist[i]){
            u = i;
        }
    }
    int s = dist[u];
    cout << 10*s + s*(s + 1ll) / 2 << endl;
    return 0;
}