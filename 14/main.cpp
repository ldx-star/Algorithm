///https://www.acwing.com/problem/content/submission/1098/

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

const int N = 110;
char g[N][N][N];
int st[N][N][N];
int X,Y,Z;
int dx[6] = {-1,0,1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

struct Point{
    int x,y,z;
};

void show(){
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            for(int k = 0; k < Z;k++){
                cout << g[i][j][k] << " ";
            }
            puts("");
        }
        puts("");
    }
}

int bfs(Point start,Point end){
    memset(st,-1,sizeof st);
    queue<Point> q;
    q.push(start);
    st[start.x][start.y][start.z] = 0;
    while(q.size()){
        Point p = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            int z = p.z + dz[i];
            if(x < 0 || x >= X || y < 0 || y >= Y || z < 0 || z >= Z || st[x][y][z] != -1||g[x][y][z] == '#')continue;
            Point tmp = {x,y,z};
            q.push(tmp);
            st[x][y][z] = st[p.x][p.y][p.z] + 1;
            if(x == end.x && y == end.y && z == end.z){
                return st[x][y][z];
            }
        }
    }
    return -1;
}

int main(){
    Point start,end;

    while(cin >> X >> Y >> Z,X || Y || Z){
        for(int i = 0 ; i < X; i++){
            for(int j = 0; j < Y; j++)
                scanf("%s",g[i][j]);
        }
        for(int i = 0; i < X; i++){
            for(int j = 0; j < Y; j++){
                for(int k = 0; k < Z;k++){
                    if(g[i][j][k] == 'S')start = {i,j,k};
                    if(g[i][j][k] == 'E')end = {i,j,k};
                }
            }
        }
        int res = bfs(start,end);
        if(res == -1){
            cout << "Trapped!" << endl;
        }else{
            printf("Escaped in %d minute(s).\n",res);
        }
    }

    return 0;
}