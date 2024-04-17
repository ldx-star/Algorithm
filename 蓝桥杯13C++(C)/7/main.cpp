#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
const int N = 1e6+10;
bool st[N];
priority_queue<int,vector<int>,greater<>> tmp;


int main()
{
    // 请在此输入您的代码
    string str;
    cin >> str;
    bool flag = true;
    do{
        memset(st,0,sizeof st);
        flag = true;
        string str_backup;
        for(int i = 1; i < str.size()-1;i++){
            if(str[i] == str[i-1] && str[i] != str[i+1]){
                if(!st[i]){
                    tmp.push(i);
                    st[i] = true;
                    flag = false;
                }
                if(!st[i+1]){
                    tmp.push(i+1);
                    st[i+1] = true;
                    flag = false;
                }
            }
            if(str[i] != str[i-1] && str[i] == str[i+1]){
                if(!st[i]){
                    tmp.push(i);
                    st[i] = true;
                    flag = false;
                }
                if(!st[i-1]){
                    tmp.push(i-1);
                    st[i-1] = true;
                    flag = false;
                }
            }
        }
        if(tmp.empty()){
            break;
        }
        for(int i = 0; i < str.size();i++){
            int e = tmp.top();
            if(i == e) {
                tmp.pop();
            }else{
                str_backup += str[i];
            }
        }
        str = str_backup;

    }while(!flag);
    if(str.empty()){
       cout << "EMPTY";
    }else{
        cout << str;
    }

    return 0;
}