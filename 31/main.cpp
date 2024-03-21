///https://www.acwing.com/problem/content/1222/
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
typedef long long LL;
const int N = 1e5+10;
LL f[N];
int w[N];
bool st[N];
int n;
vector<int> tree[N];
void dfs(int u){
    st[u] = true;
    f[u] = w[u];
    for(auto e : tree[u]){
        if(st[e] == false){
            dfs(e);
            f[u] += max(0ll,f[e]);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);

    }
    dfs(1);
    LL res = INT_MIN;
    for(int i = 1; i <= n; i++){
        res = max(res,f[i]);
    }
    cout << res << endl;
    return 0;
}