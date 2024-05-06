//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/container-with-most-water/submissions/527103360/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int res = 0;
    for(int i = 0,j = height.size()-1; i < j;){
        int area = (j - i) * min(height[i],height[j]);
        if(area > res){
            res = area;
        }
        if(height[i] > height[j]){
            j--;
        }else{
            i++;
        }

    }
    return res;
}

int main() {
//    vector <int> vint{1,2,0,1};
//    vector <int> vint{0,3,7,2,5,8,4,6,0,1};
//    vector <int> vint{0};
//    vector <int> vint{0,-1};
    vector<int> vint{2,3,10,5,7,8,9};
    maxArea(vint);
    return 0;
}