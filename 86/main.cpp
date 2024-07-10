#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5+10;

int a1[N],cnt1 = 0;

int main() {
    int n,k;
    cin >> n >> k;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num % 2 == 0){
            //偶数
            pq.push(num);
        }else{
            // 奇数
            a1[cnt1++] = num;
        }
    }
    // 求奇数的和
    int sum1 = 0;
    for(int i = 0; i < cnt1; i++){
        sum1 += a1[i];
    }
    int sum2 = 0;
    while(k-- && !pq.empty()){
        int top = pq.top();
        pq.pop();
        top /= 2;
        if(top % 2 != 0){
            // 奇数
            sum2 += top;
        }else{
            pq.push(top);
        }
    }
    while(!pq.empty()){
        sum2 += pq.top();
        pq.pop();
    }
    cout << sum1 + sum2;

    return 0;
}
// 64 位输出请用 printf("%lld")