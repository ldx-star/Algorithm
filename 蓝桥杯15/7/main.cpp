//
// Created by ldx on 24-4-19.
//
#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;
const int N = 1005;
bool g[N][N];
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        int parent;
        scanf("%d",&parent);
        if(parent == -1 )continue;
        g[i][parent] = true;
        g[parent][i] = true;
    }
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || g[i][j] )continue;
            int ans = a[i] ^ a[j];
            if(ans > max_val){
                max_val = ans;
            }
        }
    }
    cout << max_val;
    return 0;
}