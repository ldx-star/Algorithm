#include <iostream>
#include <algorithm>
using namespace std;

int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool check(int x){
    int day = x % 100; x /= 100;
    int month = x % 100; x /= 100;
    if( day > m[month]) return false;
    return true;
}

bool seque(int x){
    int a[3];
    a[0] = x % 10; x /= 10;
    a[1] = x % 10; x /= 10;
    a[2] = x % 10; x /= 10;
    if(a[0] - a[1] == 1 && a[1] - a[2] == 1) return true;
    return false;
}

int main()
{
    // 请在此输入您的代码
    int res = 0;
    for(int i = 20220101; i <= 20221231; i++){
        if(!check(i))continue;
        int tmp = i;
        while(tmp){
            int num = tmp % 1000;
            if(seque(num)){
                res++;
                break;
            }
            tmp /= 10;
        }
    }
    cout << res;
    return 0;
}