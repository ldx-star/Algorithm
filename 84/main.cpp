#include <iostream>
#include <string>
#include <vector>
#include<cstring>
using namespace std;

vector<vector<string>> ans;
int _n;
bool check(bool chess[10][10], int x,int y){
    // 检查列
    for(int i = 1; i < x; i++){
        if(chess[i][y] == true){
            return false;
        }
    }
    // 检查对角线
    for(int i = x, j = y; i > 0 && j > 0; i--, j--){
        if(chess[i][j] == true){
            return false;
        }
    }
    for(int i = x, j = y; i > 0 && j <= _n; i--, j++){
        if(chess[i][j] == true){
            return false;
        }
    }
    return true;
}
void add_ans(bool chess[10][10]){
    vector<string> strs;
    for(int i = 1; i <= _n; i++){
        string str;
        for(int j = 1; j <= _n; j++){
            if(chess[i][j] == true){
                str += "Q";
            }else{
                str += ".";
            }
        }
        strs.push_back(str);
    }
    ans.push_back(strs);
}
void solveNQueens_(bool chess[10][10], int row){
    for(int i = 1; i <= _n; i++){
        for(int j = 1; j <= _n; j++){
            if(chess[i][j] == true){
                cout << "Q ";
            }else{
                cout <<". ";
            }
        }
        puts("");
    }
    puts("");
    if(row == _n+1){
        add_ans(chess);
        return;
    }
    for(int i = 1; i <= _n; i++){
        if(check(chess,row,i)){
            chess[row][i] = true;
            solveNQueens_(chess,row+1);
            chess[row][i] = false;

        }

    }
}
vector<vector<string>> solveNQueens(int n) {
    _n = n;
    bool chess[10][10];
    memset(chess,0,sizeof chess);
    solveNQueens_(chess,1);
    return ans;
}
int main(){
    solveNQueens(4);
}