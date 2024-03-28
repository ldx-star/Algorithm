///https://www.lanqiao.cn/paper/3835/problem/595/
#include <iostream>
#include <vector>
using namespace std;
vector<int> a[7];

// 'a','b','c','d','e','f','g' --> 0,1,2,3,4,5,6

int dfs(int u){
    int res = 0;
    for(auto e : a[u]){
        res += dfs(e) + 1;
    }
    return res;
}

int main()
{
    // 请在此输入您的代码
    a[0].push_back(1);
    a[0].push_back(5);
    a[1].push_back(2);
    a[1].push_back(6);
    a[2].push_back(3);
    a[3].push_back(4);
    a[4].push_back(5);
    a[4].push_back(6);
    a[5].push_back(6);

    int res = 0;
    res += dfs(0)+1;
     res += dfs(1);
     res += dfs(2);
     res += dfs(3);
     res += dfs(4);
     res += dfs(5);
     res += dfs(6);

    cout << res;
    return 0;
}