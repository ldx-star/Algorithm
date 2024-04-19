//
// Created by ldx on 24-4-19.
//
#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

const int N = 11;
int a[N][N];
int dt[8][2] = {{-1, 0},
                {-1, 1},
                {0,  1},
                {1,  1},
                {1,  0},
                {1,  -1},
                {0,  -1},
                {-1, -1}};
int n, k;
vector<int> path;
vector<int> res;
bool ban[N][N][N][N];
bool vis[N][N];

void dfs(int sx, int sy) {
    if (!res.empty()) return;
    if (sx == n - 1 && sy == n - 1) {
        if (path.size() == n * n - 1) res = path;
        return;
    }
    if (path.size() == n * n - 1) return;
    for (int i = 0; i < 8; i++) {
        if (!res.empty()) return;
        int dx = dt[i][0], dy = dt[i][1];
        int x = sx + dx, y = sy + dy;

        if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && a[x][y] == (a[sx][sy] + 1) % k) {
            if (dx != 0 && dy != 0 && ban[x][sy][sx][y]) continue;

            ban[sx][sy][x][y] = ban[x][y][sx][sy] = true;
            vis[x][y] = true;
            path.push_back(i);
            dfs(x, y);
            path.pop_back();
            vis[x][y] = false;
            ban[sx][sy][x][y] = ban[x][y][sx][sy] = false;
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    vis[0][0] = true;
    dfs(0, 0);
    if (!res.empty()) {
        for (auto x: res) printf("%d", x);
    } else {
        puts("-1");
    }
    return 0;
}