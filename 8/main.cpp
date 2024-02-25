//
// Created by ldx on 24-2-22.
//
///https://www.acwing.com/problem/content/description/1239/
#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
int main(){
    LL x,y;
    cin >> x >> y;
    LL res = 0;
    LL start = 0;
    if(abs(x) <= y && y >= 0){
        start = (LL)(2*y-1) * 2 * y;
        res = start + x + y;
    }else if(abs(y) <= x && x >= 0){
        start = 2 * x * 2 * (LL)x;
        res = start + (x - y);
    }else if(abs(x) <= abs(y) + 1 && y <= 0){
        start = (LL)abs(y) * 2 * (2 * abs(y) + 1);
        res = start + abs(y + x);
    }else if(abs(y) <= abs(x) && x <= 0){
        start = ((LL)abs(x)*2 - 1) *((LL)abs(x)*2 - 1) ;
        res =  start + abs(x) + y-1;
    }

    cout << res << endl;
    return 0;
}