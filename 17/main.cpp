/// https://www.acwing.com/problem/content/description/1057/
#include<iostream>
using namespace std;
const int N = 1e5+10;
int a[N];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i] < a[i+1]){
            sum += a[i+1] - a[i];
        }
    }
    cout << sum;
    return 0;
}