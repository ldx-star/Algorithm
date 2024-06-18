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
bool st[11][11];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    bool flag = true;
    vector<int> res;
    int cur_x = 0;
    int cur_y = 0;
    res.push_back(matrix[cur_y][cur_x]);
    memset(st,0,sizeof st);
    st[cur_y][cur_x] = true;
    while(flag){
        for(int i = 0; i < 4; i++){
            flag = false;
            while(1){
                st[cur_y][cur_x] = true;
                int x = cur_x + dx[i];
                int y = cur_y + dy[i];
                if(x >= matrix[0].size() || y >= matrix.size() || x < 0 || y < 0 || st[y][x]){
                    break;
                }
                cur_x = x;
                cur_y = y;
                res.push_back(matrix[cur_y][cur_x]);
                flag = true;
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> nums = {{1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 }};
    spiralOrder(nums);
    return 0;
}