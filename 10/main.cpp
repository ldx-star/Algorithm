//
// Created by ldx on 24-2-22.
//
///https://www.acwing.com/problem/content/1103/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N = 210;
char g[N][N];
int dist[N][N];
int r,c;
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int bfs(PII start, PII end){
    memset(dist, -1, sizeof dist);
    queue<PII> q;
    q.push(start);
    dist[start.x][start.y] = 0;
    while(q.size()){
        PII t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int a = t.x + dx[i];
            int b = t.y + dy[i];
            if(a >= r || b >= c || a <0 || b < 0 )continue;
            if(g[a][b] == '#') continue;
            if(dist[a][b] != -1) continue;
            q.push({a,b});
            dist[a][b] =  dist[t.x][t.y] + 1;
            if(end == make_pair(a,b)) return dist[a][b];
        }
    }
    return -1;
}

int main(){


    int n;
    cin >> n;
    while(n--){
        cin >> r >> c;
        PII start,end;
        for(int i = 0; i < r; i++) scanf("%s",g[i]);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(g[i][j] == 'S')start = {i,j};
                if(g[i][j] == 'E')end = {i,j};
            }
        }
        int t = bfs(start,end);
        if(t == -1) puts("oop!");
        else{
            cout << t << endl;
        }
    }


    return 0;
}
