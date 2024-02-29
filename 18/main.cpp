/// https://www.acwing.com/problem/content/106/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1e5+10;
int a[N];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int mid = n/2;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += abs(a[mid] - a[i]);
    }
    cout << sum << endl;
    return 0;
}