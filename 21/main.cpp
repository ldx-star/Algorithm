/// https://www.acwing.com/problem/content/1237/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

typedef long long LL;
const int N = 5e5+10;
int a[N];
double pay[N];
int main(){
    int n;
    double S;
    cin >> n >> S;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    double ave;
    double average = ave = S / n;
    for(int i = 0; i < n;i++ ){
        if(a[i] <= ave){
            pay[i] = a[i];
        }
        if(a[i] > ave){
            pay[i] = ave;
        }
        if(i != n-1){
            S -= pay[i];
            ave = S / (n - i - 1);
        }
    }
    double s = 0;
    for(int i = 0; i < n; i++){
        s += (pay[i] - average)*(pay[i] - average);
    }
    printf("%.4lf", sqrt(s/n));
    return 0;
}