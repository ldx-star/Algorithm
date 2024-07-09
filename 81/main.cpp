//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/rotting-oranges/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>
#include <queue>
#include<cstring>
using namespace std;
vector<string> dig = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> ans;
string _digits;
void letterCombinations_(string &str,int dig_start){
    if(str.size() == _digits.size()){
        ans.push_back(str);
        return;
    }

    for(int i = 0; i < dig[_digits[dig_start] - '0'].size(); i++){
        str.push_back(dig[_digits[dig_start] - '0'][i]);
        letterCombinations_(str, dig_start + 1);
        str.pop_back();
    }

}
vector<string> letterCombinations(string digits) {
    _digits = digits;
    string str;
    letterCombinations_(str,0);
    return ans;
}
int main(){
    string digits = "23";
    letterCombinations(digits);

    return 0;
}