//
// Created by ldx on 24-4-19.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 20;
int arr[N][N];
bool st[N][N];
bool ban[N][N][N][N];
int n, k;
int d_x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int d_y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> res;
vector<int> path;

void dfs(int sx, int sy) {
    if (!res.empty()) return;
    if (sx == n - 1 && sy == n - 1) {
        if (path.size() == n * n - 1) res = path;
        return;
    }
    if (path.size() == n * n - 1) return;
    for (int i = 0; i < 8; i++) {
        if (!res.empty()) return;
        int dx = d_x[i], dy = d_y[i];
        int x = sx + dx, y = sy + dy;

        if (x >= 0 && x < n && y >= 0 && y < n && !st[x][y] && arr[x][y] == (arr[sx][sy] + 1) % k) {
            if (dx != 0 && dy != 0 && ban[x][sy][sx][y]) continue;

            ban[sx][sy][x][y] = ban[x][y][sx][sy] = true;
            st[x][y] = true;
            path.push_back(i);
            dfs(x, y);
            path.pop_back();
            st[x][y] = false;
            ban[sx][sy][x][y] = ban[x][y][sx][sy] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    st[0][0] = true;
    dfs(0, 0);
    if (res.empty()) {
        cout << -1;
    } else {
        for (auto e: res) {
            cout << e;
        }
    }
    return 0;
}