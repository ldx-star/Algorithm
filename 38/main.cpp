///https://www.acwing.com/problem/content/description/838/
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5+10;
int p[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    for(int i = 0; i < N; i++) p[i] = i;
    int n,m;
    cin >> n >> m;
    while(m--){
        char op;
        int a,b;
        cin >> op >> a >> b;
        if(op == 'M') p[find(a)] = find(b);
        else{
            if(find(p[a]) == find(p[b])) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}