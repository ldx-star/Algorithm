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
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // 定位列
    int l = 0;
    int r = matrix[0].size()-1;
    int t = 0;
    int b = matrix.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(matrix[b][mid] >= target){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    // 定位行
    for(int i = l; i < matrix[0].size();i++){
        t= 0;
        b = matrix.size()-1;
        while(t < b){
            int mid = t + b >> 1;
            if(matrix[mid][i] >= target){
                b = mid;
            }else{
                t = mid + 1;
            }
        }
        if(matrix[t][i] == target){
            return true;
        }
    }
    return false;
}

int main() {
//    vector<vector<int>> nums = {{ 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 }};
    vector<vector<int>> nums = {{-5}};
    searchMatrix(nums,-2);
    return 0;
}