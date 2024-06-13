//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/maximum-subarray/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>
const int N = 1e5+10;
int f[N];
using namespace std;
int maxSubArray(vector<int>& nums) {
    if(nums.size() == 1){
        return nums[0];
    }
    memset(f,0,sizeof f[0] * N);
    f[0] = nums[0];
    for(int i = 1; i < nums.size();i++){
        if(f[i-1] < 0){
            f[i] = nums[i];
        }else{
            f[i] = f[i-1]+nums[i];
        }
    }
    int res = -1e4-10;
    for(int i = 0; i < N; i++){
        res = max(res,f[i]);
    }
    return res;
}

int main() {
    vector<int> nums{-2, -1};
    cout << maxSubArray(nums);
    return 0;
}