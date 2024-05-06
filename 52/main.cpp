//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;
const int N = 2e4 + 10;
bool a[N];

int trap(vector<int> &height) {
    int res = 0;
    for (int i = 0; i < height.size(); i++) {
        int j = i + 1;
        if (j > height.size() - 1) {
            break;
        }
        int area = 0;
        bool flag = false;
        int max_val = 0;
        int max_idx = j;
        while (j < height.size()) {
            if (height[j] >= height[i]) {
                flag = true;
                area = height[i] * (j - i - 1);

                for (int k = i + 1; k < j; k++) {
                    area -= height[k];
                }
                res += area;
                i = j - 1;
                break;
            }
            if (max_val < height[j]) {
                max_idx = j;
                max_val = height[j];
            }
            j++;
        }
        if (!flag) {
            area = height[max_idx] * (max_idx - i - 1);
            for (int k = i + 1; k < max_idx; k++) {
                area -= height[k];
            }
            res += area;
            i = max_idx - 1;
        }
    }
    return res;
}


int main() {
//    vector <int> vint{1,2,0,1};
//    vector <int> vint{0,3,7,2,5,8,4,6,0,1};
//    vector <int> vint{0};
//    vector <int> vint{0,-1};
    vector<int> vint{0,2,0};
    trap(vint);
    return 0;
}