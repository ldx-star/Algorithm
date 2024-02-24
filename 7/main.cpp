//
// Created by ldx on 24-2-22.
//
///https://www.acwing.com/activity/content/problem/content/1724/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 2*1e6+10;

LL s[N],bp[N],b[N];
int A,B,C,m;
int d[8][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, -1},
        {0, 1, 0, -1},
        {0, 1, 1, 1},
        {1, 0, 0, -1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, -1},
};
int op[N/2][7];
int get(int i,int j,int k){
    return (i * B + j) * C + k;
}
bool check(int mid){
    memcpy(b,bp,sizeof b);
    for(int i = 1; i <= mid; i++){
        int x1 = op[i][0],x2 = op[i][1];
        int y1 = op[i][2],y2 = op[i][3];
        int z1 = op[i][4],z2 = op[i][5];
        int h = op[i][6];
        b[get(x1,  y1,  z1)]   -= h;
        b[get(x1,  y2+1,z1)]   += h;
        b[get(x1,  y1,  z2+1)] += h;
        b[get(x1,  y2+1,z2+1)] -= h;
        b[get(x2+1,y1,  z1)]   += h;
        b[get(x2+1,y2+1,z1)]   -= h;
        b[get(x2+1,y1,  z2+1)] -= h;
        b[get(x2+1,y2+1,z2+1)] += h;
    }
    memset(s, 0, sizeof s);
    for (int i = 1; i <= A; i ++ )
        for (int j = 1; j <= B; j ++ )
            for (int k = 1; k <= C; k ++ )
            {
                s[get(i, j, k)] = b[get(i, j, k)];
                for (int u = 1; u < 8; u ++ )
                {
                    int x = i - d[u][0], y = j - d[u][1], z = k - d[u][2], t = d[u][3];
                    s[get(i, j, k)] -= s[get(x, y, z)] * t;
                }

                if (s[get(i, j, k)] < 0) return true;
            }

    return false;
}
int main(){

    cin >> A >> B >> C >> m;
    for (int i = 1; i <= A; i ++ )
        for (int j = 1; j <= B; j ++ )
            for (int k = 1; k <= C; k ++ ){
                scanf("%lld", &s[get(i, j, k)]);
            }

    // // //构建差分数组
    for(int i = 1; i <= A; i++){
        for(int j = 1; j <= B; j++){
            for(int k = 1; k <= C; k++){
                for(int c = 0; c < 8;c++){
                    int x = i - d[c][0], y = j - d[c][1],z = k - d[c][2],t = d[c][3];
                    bp[get(i,j,k)] += s[get(x,y,z)] * t;
                }
            }
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < 7; j++){
            scanf("%d",&op[i][j]);
        }
    }
    int l = 1, r = m;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;


    for (int i = 1; i <= A; i ++ )
        for (int j = 1; j <= B; j ++ )
            for (int k = 1; k <= C; k ++ )
                scanf("%lld", &s[get(i, j, k)]);

    return 0;
}