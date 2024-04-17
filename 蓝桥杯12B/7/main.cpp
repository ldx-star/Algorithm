#include <iostream>

using namespace std;
const int N = 110, M = 200010, B = M / 2;
int n;
int w[N];
bool dp[N][M];

int main() {
    // 请在此输入您的代码
    cin >> n;
    int m = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        m += w[i];
    }
    dp[0][B] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = -m; j <= m; j++) {
            dp[i][j + B] = dp[i - 1][j + B];
            if (j + w[i] <= m) dp[i][j + B] |= dp[i - 1][j + w[i] + B];
            if (j - w[i] >= -m) dp[i][j + B] |= dp[i - 1][j - w[i] + B];
        }
    }
    int count = 0;
    for (int i = 1; i <= m; i++) {
        if (dp[n][i + B]) count++;
    }
    cout << count;
    return 0;
}