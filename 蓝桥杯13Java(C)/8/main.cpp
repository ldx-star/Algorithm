#include <iostream>
using namespace std;
typedef long long LL;

const int N = 1010;
int a[N];
int main() {
    int n,x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> a[n];
    }
    for(int i = 1; i < N; i++){

    }
    LL max_val = 0;
    LL max_idx = 0;
    for(int i = 0; i < 10000000; i++){
        LL g = gcd(a+i,b+i);
        if(g > max_val){
            max_val = g;
            max_idx = i;
        }
    }
    cout << max_idx;
    return 0;
}
