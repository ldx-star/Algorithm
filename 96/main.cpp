#include <iostream>
#include <string>
#include <climits>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


bool dp[310];
bool wordBreak(string s, vector<string>& wordDict) {
    string str = " ";
    str += s;
    s = str;
    memset(dp,0,sizeof dp);
    dp[0] = true;
    for(int i = 1; i <= s.size(); i++){
        for(int j = 0; j < wordDict.size(); j++){
            if(i >= wordDict[j].size()){
                string sub = s.substr(i - wordDict[j].size()+1, wordDict[j].size());
                bool flag = sub == wordDict[j] ? true : false;
                dp[i] = dp[i-wordDict[j].size()] && flag;
                if(dp[i] == true){
                    break;
                }
            }

        }
    }
    return dp[s.size()];
}

int main() {
    string str ="leetcode";
    vector<string> wordDict = {"leet", "code"};
    wordBreak(str,wordDict);
    return 0;
}