#include <iostream>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b){
    return b ? gcd(b,a % b) : a;
}

int main() {
    LL a, b;
    cin >> a >> b;
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
