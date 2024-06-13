//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/minimum-window-substring/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;
int alpha_dig1[52];
int alpha_dig2[52];
bool check(){
    for(int i = 0; i < 52;i++){
        if(alpha_dig1[i] != 0 && alpha_dig2[i] < alpha_dig1[i]){
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    for(int i = 0; i < t.size(); i++){
        char ch = t[i];
        if(ch >= 'a' && ch <= 'z'){
            alpha_dig1[ch - 'a']++;
        }
        if(ch >= 'A' && ch <= 'Z'){
            alpha_dig1[ch - 'A' + 26]++;
        }
    }
    int l = 0, r = 0;
    int min_l = 0, min_r = 0,min_len = 1e5+10;
    string res;
    string tmp;
    while(r < s.size() || l < s.size()){
        if(!check()){
            if(r >= s.size()) break;
            char ch = s[r];
            if(ch >= 'a' && ch <= 'z'){
                alpha_dig2[ch - 'a']++;
            }
            if(ch >= 'A' && ch <= 'Z'){
                alpha_dig2[ch - 'A' + 26]++;
            }
            r++;
        }else{
            if(l >= s.size()) break;
            int len = r - l;
            if(len < min_len){
                min_l = l;
                min_r = r;
                min_len = len;
            }

            char ch = s[l];
            if(ch >= 'a' && ch <= 'z'){
                alpha_dig2[ch - 'a']--;
            }
            if(ch >= 'A' && ch <= 'Z'){
                alpha_dig2[ch - 'A' + 26]--;
            }
            l++;
        }
    }
    res = s.substr(min_l,min_r-min_l);
    return res;

}

int main() {
    string s = "cabwefgewcwaefgcf";
    string t = "cae";
    cout << minWindow(s,t);
    return 0;
}