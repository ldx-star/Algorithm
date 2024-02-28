/// https://www.acwing.com/problem/content/1235/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;
char g[N][N];
int st[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n;


bool bfs(PII start) {
    queue<PII> q;
    q.push(start);
    st[start.first][start.second] = 0;
    bool res = false;
    while (q.size()) {
        bool flag = true;
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= n || st[x][y] != -1)continue;
            if(g[x][y] == '.'){
                g[start.first][start.second] = '?';
                flag = false;
                continue;
            }
            st[x][y] = 0;
            q.push(make_pair(x, y));
        }
        if(flag){
            res = true;
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
    }
    memset(st, -1, sizeof st);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (st[i][j] != -1) continue;
            if (g[i][j] == '#') {
                if(!bfs(make_pair(i, j))) {
                    cnt++;
                }
            }

        }
    }
    cout << cnt << endl;
    return 0;
}