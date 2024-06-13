//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/sliding-window-maximum/description/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>
#include <set>
#include <queue>

using namespace std;
typedef pair<int,int> PII;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    priority_queue<PII> q_PII;

    for(int i = 0; i < k ; i++){
        q_PII.push({nums[i],i});
    }
    res.push_back(q_PII.top().first);
    for(int i = k; i <nums.size(); i++){
        q_PII.push({nums[i],i});
        int left = i - k + 1;
        PII top = q_PII.top();
        while(top.second < left){
            q_PII.pop();
            top = q_PII.top();
        }
        res.push_back(top.first);
    }
    return res;
}



int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    maxSlidingWindow(nums,k);

    return 0;
}