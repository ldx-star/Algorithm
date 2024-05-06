//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/group-anagrams/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;


vector <vector<string>> groupAnagrams(vector <string> &strs) {
    map<string, vector<string>> mis;
    for (int i = 0; i < strs.size(); i++) {
        string tmp = strs[i];
        sort(tmp.begin(),tmp.end());
        mis[tmp].push_back(strs[i]);
    }
    vector <vector<string>> res;
    for (auto e: mis) {
        res.push_back(e.second);
    }
    return res;
}

int main() {
    vector <string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
}