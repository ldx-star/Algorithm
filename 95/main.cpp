#include <iostream>
#include <string>
#include <climits>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int dp[10010];
vector<int> a;

int numSquares(int n) {
    memset(dp, 0x3f3f3f, sizeof dp);
    for (int i = 1; i <= n / i; i++) {
        a.push_back(i * i);
    }
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < a.size() && a[j] <= i; j++) {
            int k = i / a[j];
            dp[i] = min(dp[i - k * a[j]] + k,dp[i]);
        }
    }


    return dp[n];

}

int main() {
    numSquares(12);
    return 0;
}