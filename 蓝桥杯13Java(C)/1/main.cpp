//
// Created by ldx on 24-4-15.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    // 请在此输入您的代码
    string str = "WHERETHEREISAWILLTHEREISAWAY";

    sort(str.begin(),str.end());
    cout <<str;
    return 0;
}