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
int sum[N];

int query(int l, int r) {
    return sum[r] - sum[l - 1];
}

int subarraySum(vector<int> &nums, int k) {
    map<int, int> my_map;
    int len = nums.size();
    int ans = 0;
    my_map[0] = 1;
    for (int i = 0; i < len; i++) {
        sum[i+1] = sum[i] + nums[i];
    }
    for (int i = 1; i <= len; i++) {
        if (my_map.find(sum[i] - k) != my_map.end()) {
            ans += my_map[sum[i] - k];
        }
        my_map[sum[i]]++;
    }
    return ans;
}


int main() {

    vector<int> nums = {1, 2, 1, 2, 1};
    int k = 3;
    subarraySum(nums, k);
    return 0;
}