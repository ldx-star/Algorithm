//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/3sum/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1, k = nums.size() - 1; j < nums.size() && k > j && k < nums.size(); j++) {
            while(k > j && nums[i] + nums[j] + nums[k] > 0){
                k--;
            }
            if (nums[i] + nums[j] + nums[k] == 0 && i != k && j != k) {
                vector<int> tmp{nums[i], nums[j], nums[k]};
                res.push_back(tmp);
                while (i + 1 < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    i++;
                }
                while (j + 1 < nums.size() - 1 && nums[j] == nums[j + 1]) {
                    j++;
                }
                while (k - 1 >= 0 && nums[k] == nums[k - 1]) {
                    k--;
                }
            }

        }

    }
    return res;
}

int main() {
//    vector <int> vint{1,2,0,1};
//    vector <int> vint{0,3,7,2,5,8,4,6,0,1};
//    vector <int> vint{0};
//    vector <int> vint{0,-1};
    vector<int> vint{-1,0,1,2,-1,-4,-2,-3,3,0,4};
    threeSum(vint);
    return 0;
}