//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/rotate-array/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;

void rotate(vector<int> &nums, int k) {
    vector<int> res(nums.size());
    int j = nums.size() - 1;
    for (int i = k - 1; i >= 0; i--) {
        res[i] = nums[j--];
    }
    for (int i = nums.size() - 1; j >= 0; i--) {
        res[i] = nums[j--];
    }
    nums = res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    return 0;
}