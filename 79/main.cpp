//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/rotting-oranges/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>
#include <queue>
#include<cstring>
using namespace std;
int st[11][11];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

queue<pair<int,int>> q_grid;
int last = 0;
int cur = 0;
int row,col;

bool bfs(vector<vector<int>>& grid, int x, int y){
    bool flag = false;
    for(int i = 0; i < 4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x < 0 || new_y < 0 || new_x >= row || new_y >= col || st[new_x][new_y] == 1 || grid[new_x][new_y] == 0){
            continue;
        }else{
            grid[new_x][new_y] = 2;
            q_grid.push({new_x,new_y});
            st[new_x][new_y] = 1;
            cur++;
            flag = true;
        }

    }
    return flag;
}

int orangesRotting(vector<vector<int>>& grid) {
    row = grid.size();
    col = grid[0].size();
    int ret = 0;
    // 找到所有的烂橘子
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 2){
                q_grid.push({i,j});
                st[i][j] = 1;
                last++;
            }
        }
    }
    while(!q_grid.empty()){
        bool flag = false;
        for(int i = 0; i < last; i++){
            pair<int,int> front = q_grid.front();
            flag = (bfs(grid,front.first,front.second) || flag);
            q_grid.pop();
        }
        last = cur;
        cur = 0;
        if(flag) ret++;
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 1){
                return -1;
            }
        }
    }
    return ret;
}

int main() {
    memset(st,0,sizeof st);
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    orangesRotting(grid);
}