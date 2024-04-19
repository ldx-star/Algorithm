#include <iostream>

using namespace std;
const int N = 110;
const int mod = 1000000007;
int f[N][N][N];

int main() {
    // 请在此输入您的代码
    int n, m;
    cin >> n >> m;
    f[0][0][2] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m; k++) {
                if (i >= 1 && k % 2 == 0) f[i][j][k] = (f[i][j][k] + f[i - 1][j][k / 2]) % mod;
                if (j >= 1)f[i][j][k] = (f[i][j][k] + f[i][j - 1][k + 1]) % mod;


            }
        }
    }
    cout << f[n][m - 1][1];
    return 0;
}