//
// Created by ldx on 24-2-2.
//
///https://www.acwing.com/problem/content/description/1267/

#include<iostream>
using namespace std;
const int N = 32010;
int tr[N];
int level[15010];

int lowbit(int x){
    return x & -x;
}
void add(int x){
    for(int i = x; i <= N; i += lowbit(i)){
        tr[i]++;
    }
}
int query(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)){
        res += tr[i];
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        level[query(x+1)]++;
        add(x+1);
    }
    for(int i = 0; i < n;i++){
        cout << level[i] << endl;
    }

    return 0;
}