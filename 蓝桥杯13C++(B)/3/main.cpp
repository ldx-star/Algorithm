#include <iostream>
using namespace std;
typedef long long LL;
int main()
{
    // 请在此输入您的代码
    LL a,b,n;
    cin >> a >> b >> n;
    LL res = 0;
    LL count = 0;
    LL day = 1;
    while(1){
        if(day % 7 != 0 && day % 7 != 6){
            count += a;
        }else{
            count += b;
        }
        day++;
        res++;
        if(count >= n){
            cout << res;
            break;
        }

    }
    return 0;
}