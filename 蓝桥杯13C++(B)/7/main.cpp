#include <iostream>

using namespace std;
const int N = 10000010;
const int mod = 1000000007;
int f[N][4];
int g[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 0, 0, 0}
};

int main() {
    // 请在此输入您的代码
    int n;
    cin >> n;
    f[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                f[i + 1][k] = (f[i + 1][k] + f[i][j] * g[j][k]) % mod;
            }
        }
    }
    cout << f[n + 1][0];
    return 0;
}