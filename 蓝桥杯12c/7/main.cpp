#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    // 请在此输入您的代码
    LL time;
    cin >> time;
    LL time_day = time % (24*60*60*1000);
    int time_s = time_day / 1000;
    int time_m = time_s / 60;
    int hours = time_m / 60;
    int minutes = time_m - (hours * 60);
    int seconds = time_s - (hours * 60 * 60 + minutes * 60);
    printf("%.2d:%.2d:%.2d",hours,minutes,seconds);
    return 0;
}