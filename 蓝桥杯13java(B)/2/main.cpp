#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool check(string str){
    int len = str.size() / 2;
    if(str.size() % 2 != 0){
        len = len+1;
    }
    for(int i = 0; i < len-1; i++){
        if(str[i] > str[i+1]){
            return false;
        }
    }
    return true;
}

int main()
{
    // 请在此输入您的代码
    int count = 0;
    for(int i = 2022; i <= 2022222022;i++){
        string str1 = to_string(i);
        if(!check(str1)) continue;
        string str2 = str1;
        std::reverse(str2.begin(), str2.end());
        if(str1 == str2){
            cout << str1 << endl;
            count++;
        }
    }
    cout << count;
    return 0;
}