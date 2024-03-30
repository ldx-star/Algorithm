///https://www.lanqiao.cn/paper/3833/problem/1562/
#include <iostream>
#include <cmath>
using namespace std;

int Month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool check(int x){
    int day = x % 100;
    x /= 100;
    int month = x % 100;
    x /= 100;
    int year = x;
    if(day <=0 || day > 31) return false;
    if(month <= 0 || month > 12) return false;
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        //是闰年
        Month[2] = 29;
    }else{
        Month[2] = 28;
    }
    if(day > Month[month])return false;
    return true;
}

int sum(int x){
    int res = 0;
    while(x){
        res = res + x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    // 请在此输入您的代码
    int count = 0;
    for(int i = 20010101; i <= 20211231; i++){
        if(i == 20200229){
            int a = 10;
        }
        int year,month,day;
        if(check(i)){
            int tmp = i;
            day = tmp % 100;
            tmp /= 100;
            month =  tmp % 100;
            tmp /= 100;
            year = tmp;
            int res = sum(day) + sum(month) + sum(year);
            if(abs((res / (int)sqrt(res)) - sqrt(res)) < 1e-9 ){
                count++;
            }
        }
    }
    cout << count;
    return 0;
}