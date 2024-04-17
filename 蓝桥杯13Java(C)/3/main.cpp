#include <iostream>
#include <string>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int H = 1189, W = 841;
    string str;
    cin >> str;
    int n = str[1] - '0';
    for(int i = 0; i < n;i++){
        int tmp = H / 2;
        H = W;
        W = tmp;
    }
    cout <<H <<endl;
    cout <<W <<endl;
    return 0;
}