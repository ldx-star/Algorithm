#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n;
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    int tmp = 1;
    int sum = 1;
    for(int i = 1; i < 30; i++){
        tmp *= 3;
        sum += tmp;
        if (sum >= n){
            cout << i+1;
            break;
        }
    }
    return 0;
}