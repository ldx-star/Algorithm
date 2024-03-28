///https://www.acwing.com/problem/content/1244/
#include<iostream>

using namespace std;
const int N = 1e6+10;
int a[N];
int p[N];
int find(int x){
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}
int main(){
    for(int i = 0; i < N; i++) p[i] = i;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(p[a[i]] != a[i])
        {
            a[i] = find(a[i]);
        }
        p[a[i]] = p[a[i]+1];
    }
    for(int i =0 ; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}