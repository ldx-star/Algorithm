///https://www.lanqiao.cn/paper/3833/problem/1562/
#include <iostream>
#include <cmath>
#include<vector>

using namespace std;
const int N = 7;
int node[2022][2] = {0};

int dfs(int root) {
    int w_l = 0, w_r = 0;
    if (root * 2 <= N) {
        w_l = dfs(root * 2);
    }
    if (root * 2 + 1 <= N) {
        w_r = dfs(root * 2 + 1);
    }
    if(node[root][0] == 0 && node[root][1] == 0) return 0;
    return 1 + 2 * w_l + 3 * w_r + node[root][0] * node[root][0] * node[root][1];
}

int dfs_node(int root) {
    if (root > N) {
        return -1;
    }
    node[root][0] = dfs_node(root * 2) + 1;
    node[root][1] = dfs_node(root * 2 + 1) + 1;
    return node[root][0] + node[root][1];
}

int main() {
    // 请在此输入您的代码
    dfs_node(1);
    cout << dfs(1);
    return 0;
}