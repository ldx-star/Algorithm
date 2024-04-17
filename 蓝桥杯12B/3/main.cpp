#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;

int main()
{
    // 请在此输入您的代码
    vector<PII> v;
    vector<double>res;
    for(int i = 0; i < 20;i++){
        for(int j = 0; j < 21; j++){
            v.push_back({i,j});
        }
    }
    for(int i = 0; i < v.size();i++){
        for(int j = 0; j < v.size();j++){
             double s = (v[j].second - v[i].second) / (v[j].first - v[i].first);
            res.push_back(s);
        }
    }
    sort(res.begin(),res.end());

    return 0;
}