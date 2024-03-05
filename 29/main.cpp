/// https://www.acwing.com/problem/content/1052/

#include<iostream>
using namespace std;
int dp[20][20];
int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        dp[0][0] = 1;
        for(int i = 0; i <= m ;i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i][j-1];
                if(i >= j)dp[i][j] += dp[i - j][j];
            }
        }
        cout << dp[m][n] << endl;
    }
    return 0;
}