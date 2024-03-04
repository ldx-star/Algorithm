/// https://www.acwing.com/problem/content/1301/

#include<iostream>
using namespace std;
typedef long long LL;

int exgcd(LL a, LL b, LL &x,LL &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b,a % b,y,x);
    y -= a/b * x;
    return d;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        LL n,d,x,y,a,b;
        cin >> n >> d >> x >> y;
        int gcd = exgcd(n,d,a,b);
        if((y - x) % gcd){
            cout << "Impossible" << endl;
        }else{
            b = b * (y - x) / gcd;
            n /= gcd;
            cout << (b % n + n) % n << endl;
        }
    }
}