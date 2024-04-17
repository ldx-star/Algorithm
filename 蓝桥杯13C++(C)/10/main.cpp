#include <iostream>
#include <map>
using namespace std;
const int N = 100010;
int a[N];
map<int,int> my_map;
int main()
{
  // 请在此输入您的代码
  int n;
  cin >>n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  int m;
  cin >> m;
  while(m--){
    my_map.clear();
    int res = 0;
    int l,r, k;
    cin >> l >> r >>k;
    for(int i = l; i <= r; i++){
      my_map[a[i]]++;
    }
    for(auto e : my_map){
      if(e.second == k) res++;
    }
    cout <<res<<endl;
  }
  return 0;
}