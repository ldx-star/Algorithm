//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;


int longestConsecutive(vector<int> &nums) {
    if (!nums.size()) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    //去重
    int len = 0;
    for (int i = 0, j = -1; i < nums.size(); i++) {
        if (j == -1 || nums[i] != nums[j]) {
            nums[++j] = nums[i];
            len = j;
        }
    }
    if (len < 2) {
        return len + 1;
    }
    int res = 0;
    int i = 0, j = 0;
    for (; i <= len - 1; i++) {
        if (nums[i + 1] - nums[i] > 1) {
            if ((i - j + 1) > res) {
                res = i - j + 1;
            }
            j = i + 1;
        }
    }
    if ((i - j + 1) > res) {
        res = i - j + 1;
    }
    return res;
}

int main() {
//    vector <int> vint{1,2,0,1};
//    vector <int> vint{0,3,7,2,5,8,4,6,0,1};
//    vector <int> vint{0};
//    vector <int> vint{0,-1};
    vector<int> vint{-8, -4, 9, 9, 4, 6, 1, -4, -1, 6, 8};
    longestConsecutive(vint);
    return 0;
}