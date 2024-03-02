/// https://www.acwing.com/problem/content/description/1248/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
const int N = 1e5+10;
int a[N];
int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int d = 0;
    for(int i = 0; i < n; i++) d = gcd(d,a[i]-a[0]);
    if(d == 0) cout << n << endl;
    else cout << (a[n-1] - a[0]) / d + 1 << endl;
    return 0;
}