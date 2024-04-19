#include <iostream>
#include <string>
using namespace std;
const int N = 30;
int a[N];
int main()
{
    // 请在此输入您的代码
    string str;
    cin >> str;
    int max_val = 0;
    for(int i = 0; i < str.size(); i++){
        a[str[i]-'A']++;
        if(max_val < a[str[i]-'A']){
            max_val =  a[str[i]-'A'];
        }
    }
    for(int i = 0; i < N; i++){
        if(a[i] ==max_val){
            cout << char( i + 'A');
        }
    }

    return 0;
}