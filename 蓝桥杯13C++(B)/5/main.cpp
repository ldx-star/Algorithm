#include <iostream>
using namespace std;
const int N = 510;
int a[N][N];
int s[N][N];
int Row,Col,K;

int check(int n ,int m){
    int res = 0;
    for(int i = 1; i <= Row; i++){
        for(int j = 1; j <= Col; j++){
            int r = n + i-1;
            int c = m + j-1;
            if(r <= Row && c <= Col){
                int sum = s[r][c] + s[i-1][j-1] - s[r][j-1] - s[i-1][c];
                if(sum <= K )res++;
            }
        }
    }
    return res;
}

int main()
{
    // 请在此输入您的代码
    cin >> Row >> Col >> K;
    for(int i = 1; i <= Row; i++){
        for(int j = 1; j <= Col; j++){
            int num;
            cin >> num;
            s[i][j] = num + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
    int res = 0;
    for(int i = 1;i <= Row; i++){
        for(int j = 1; j <= Col; j++){
            res += check(i,j);
        }
    }
    cout << res;
    return 0;
}