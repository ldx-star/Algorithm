#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 1e9+7;

int main() {
    // 请在此输入您的代码
    LL n;

    cin >> n;
    LL res = 0;

    for(LL i = 1; i <= n; i++){
        LL tmp = n / i * i * i;
        res += tmp % mod;
    }

    cout << res % mod;
    return 0;

}