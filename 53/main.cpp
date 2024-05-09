//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;


int lengthOfLongestSubstring(string s) {
    if(s.size() == 0) return 0;
    int a[128] = {0};
    int ans = 0;
    for(int i = 0, j = 0; i < s.size();i++){
        if(a[s[i]] == 0 ){
            a[s[i]]++;
        }else if(a[s[i]] != 0 && s[j] != s[i] ){
            while(s[j] != s[i]){
                a[s[j]]--;
                j++;
            }
            j++;
        }else {
            j++;
        }
        int count = 0;
        for(int k = 0; k < 128;k++){
             count += a[k];
        }
        if(count > ans){
            ans = count;
        }

    }

    return ans;
}


int main() {
    string str ="abcabcbb";
    lengthOfLongestSubstring(str);
    return 0;
}