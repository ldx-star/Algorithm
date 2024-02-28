//
// Created by ldx on 24-2-26.
//
/// https://www.acwing.com/problem/content/1115/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int X,Y;
const int N = 30;
char g[N][N];
bool st[N][N];
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};

int dfs(int a,int b){
    int cnt = 1;
    st[a][b] = true;
    for(int i = 0; i < 4; i++){
        int x = a + dx[i];
        int y = b + dy[i];
        if(x < 0 || x >= X || y < 0 || y >= Y)continue;
        if(st[x][y])continue;
        if(g[x][y] != '.')continue;
        cnt += dfs(x,y);
    }
    return cnt;
}

int main(){

    int x,y;
    while(cin >> Y >> X, X || Y){
        for(int i = 0; i < X; i++)scanf("%s",g[i]);
        for(int i = 0; i < X; i++){
            for(int j = 0; j < Y; j++){
                if(g[i][j] == '@'){
                    x = i;
                    y = j;
                }
            }
        }
        memset(st,0,sizeof st);
        cout << dfs(x,y) << endl;
    }

    return 0;
}