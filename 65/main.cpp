//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/first-missing-positive/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size() + 1;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < 1 || nums[i] > nums.size()){
            nums[i] = 0;
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % n == 0) continue;
        nums[nums[i] % n - 1] += n;
    }

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < n){
            return i + 1;
        }
    }
    return n;
}

int main() {
    vector<int> nums = {3, 4, -1, 1};
    cout << firstMissingPositive(nums);
    return 0;
}