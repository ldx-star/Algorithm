#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
struct Attack{
    int a,b,c;
};
struct Compare{
    bool operator()(Attack A1,Attack A2) {
        return A1.a < A2.a;
    }
};

typedef priority_queue<Attack, vector<Attack>,Compare> q_Attack;
q_Attack q_attack;
int main() {
    // 请在此输入您的代码
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int c = ceil((double)a/b);
        q_attack.push({a,b,c});
    }
    LL res = 0;
    while (m--) {
        Attack top = q_attack.top();
        q_attack.pop();
        res += top.a;
        if(top.c){
            top.a -= top.b;
            top.c -= 1;
        }
        q_attack.push(top);
    }
    cout << res << endl;
    return 0;
}