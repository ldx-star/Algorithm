//
// Created by ldx on 24-4-15.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef map<int, int> MII;
typedef long long LL;
int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


bool is_leap(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    return false;
}

bool check_year(int year) {
    MII digit_year;
    for (int i = 0; i < 4; i++) {
        int digit = year % 10;
        digit_year[digit]++;
        year /= 10;
    }
    if (digit_year.size() != 2) return false;
    m[2] = is_leap(year) ? 29 : 28;
    return true;
}

bool check_md(int md) {
    int day = md % 100;
    md /= 100;
    int month = md % 100;
    if (month <= 0 || month > 12) return false;
    if (day > m[month] || day <= 0) return false;
    return true;
}

bool check_hm(int hm) {
    int minute = hm % 100;
    hm /= 100;
    int hour = hm % 100;
    if (minute > 59) return false;
    if (hour > 23) return false;
    return true;
}


int main() {
    // 请在此输入您的代码
    int count = 0;
    for (int i = 111; i < 10000; i++) {
        if (check_year(i)) {
            for (int j = 100; j < 1300; j++) {
                if(i == 200 && j == 200){
                    int a = 10;
                }
                if (check_md(j)) {
                    for (int k = 0; k < 2400; k++) {
                        if(i == 200 && j == 200 && k ==  2){
                            int a = 10;
                        }
                        if (check_hm(k)) {
                            MII digit_year;
                            MII digit_md;
                            MII digit_hm;
                            int year = i;
                            int md = j;
                            int hm = k;
                            for (int i = 0; i < 4; i++) {
                                digit_year[year % 10]++;
                                digit_md[md % 10]++;
                                digit_hm[hm % 10]++;
                                year /= 10;
                                md /= 10;
                                hm /= 10;
                            }
                            if (digit_hm.size() != 2 || digit_year.size() != 2 || digit_md.size() != 2) continue;
                            bool flag1 = false;
                            bool flag2 = false;
                            for (auto e: digit_year) {
                                flag1 = false;
                                int key = e.first;
                                int value = e.second;
                                if (digit_md[key] != value || digit_hm[key] != value) break;
                                flag1 = true;
                                if (value == 3) flag2 = true;
                            }
                            if (flag1 && flag2) {
                                count++;
                                cout << "i: " << i << " j: " << j << " k: " << k << endl;
                            }
                        }
                    }
                }

            }
        }

    }
    cout << count;
    return 0;
}