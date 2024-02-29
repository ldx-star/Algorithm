/// https://www.acwing.com/problem/content/description/124/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const int N = 1e6+10;
LL a[N];
LL b[N];
int main(){
    int n;
    cin >> n;
    LL sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int average = sum / n;
    for(int i = 1; i < n; i++){
        b[i] = b[i-1] - average + a[i];
    }
    int mid = n / 2;
    sort(b,b+n);
    sum = 0;
    for(int i = 0; i < n;i++){
        sum += abs(b[mid] - b[i]);
    }
    cout << sum;
    return 0;
}