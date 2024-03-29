///https://www.acwing.com/problem/content/description/1236/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
int f[4][1010];
vector<int> a[1010];

int main() {
    int n, K;
    cin >> n >> K;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x % K].push_back(x);
    }
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i < K; i++) {
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
        for (int u = 0; u < 3 && u < a[i].size(); u++) {
            int x = a[i][u];
            for (int j = 3; j >= 1; j--) {
                for (int k = 0; k < K; k++) {
                    f[j][k] = max(f[j][k], f[j - 1][(((k - x) % K) + K) % K] + x);
                }
            }
        }

    }
    cout << f[3][0];
    return 0;
}