//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/find-all-anagrams-in-a-string/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;


vector<int> findAnagrams(string s, string p) {
    map<char, int> a;
    map<char, int> b;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        a[ch] = 0;
        b[ch] = 0;
    }
    for (int i = 0; i < p.size(); i++) {
        a[p[i]]++;
        b[s[i]]++;
    }
    vector<int> res;
    for (int l = 0, r = p.size() - 1; r < s.size(); l++, r++) {
        if (l != 0)b[s[r]]++;
        auto it1 = a.begin();
        auto it2 = b.begin();
        bool flag = true;
        for (; it1 != a.end() && it2 != b.end(); it1++, it2++) {
            auto tmp1 = *(it1);
            auto tmp2 = *(it2);
            if (tmp1.first != tmp2.first || tmp1.second != tmp2.second) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res.push_back(l);
        }
        if (b[s[l]] != 0) b[s[l]]--;


    }
    return res;
}


int main() {
    string str1 = "cbaebabacd";
    string str2 = "acb";
    findAnagrams(str1, str2);
    return 0;
}