#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int a[N];
bool func(int i,int j){
    return i > j;
}
int main()
{
    // 请在此输入您的代码
    for(int i = 1; i < N;i++) a[i] = i;
    int n,m;
    cin >> n >> m;
    stack<int> st;
    while(m--){
        int p,q;
        cin >> p >> q;
        if(p == 0){
            for(int i = 1; i <= q; i++){
                st.push(a[i]);
            }
            for(int i = 1; i <= q; i++){
                a[i] = st.top();
                st.pop();
            }
        }else{
            for(int i = q; i <= n; i++){
                st.push(a[i]);
            }
            for(int i = q; i <= n; i++){
                a[i] = st.top();
                st.pop();
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }

    return 0;
}