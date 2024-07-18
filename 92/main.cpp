#include <iostream>
#include <string>
#include <climits>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
string decodeString(string s) {
    stack<string> stack_string;
    string ret;
    for(int i = 0 ; i < s.size();i++ ){
        if(s[i] != ']'){
            string str;
            str += s[i];
            stack_string.push(str);
        }else{
            string tmp;
            while(stack_string.top() != "["){
                tmp = stack_string.top() + tmp;
                stack_string.pop();
            }
            stack_string.pop();
            string num_string;
            while(!stack_string.empty() && stack_string.top() >= "0" && stack_string.top() <= "9"){
                num_string = stack_string.top() + num_string;
                stack_string.pop();
            }
            int num = stoi(num_string);
            string str;
            for(int i = 0; i < num; i++){
                str += tmp;
            }
            stack_string.push(str);

        }
    }
    while(!stack_string.empty()){
        string top = stack_string.top();
        stack_string.pop();
        ret = top + ret;
    }
    return ret;
}
int main(){
    string str = "100[str]";
    decodeString(str);
    return 0;
}