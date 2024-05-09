//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 2e4 + 10;
int s[N];

int subarraySum(vector<int> &nums, int k) {
    int len = nums.size();
    int ans = 0;
    memset(s, 0, sizeof s);
    for (int i = 0; i < nums.size(); i++) {
        s[i + 1] = s[i] + nums[i];
    }
    for (int i = 0; i < len; i++) {
        for (int l = 1; l + i <= len; l++) {
            int r = l + i;
            int sum = s[r] - s[l-1];
            if (sum == k) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {

    vector<int> nums = {1, 2, 3};
    int k = 3;
    subarraySum(nums, k);
    return 0;
}