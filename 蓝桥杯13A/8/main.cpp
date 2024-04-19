//
// Created by ldx on 24-4-18.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int sequence[N];
struct Object {
    LL id, x, y, z;
    double d, angle; // 到圆心的距离
    bool st;
};

bool cmp(Object O1, Object O2) {
    return O1.angle < O2.angle;
}

Object objs[N];
Object backup[N];
//2 62369
//-21690 -63748 19
//-39760 57143 45
int main() {
    // 请在此输入您的代码
    int n, L;
    cin >> n >> L;
    for (int i = 1; i <= n; i++) {
        LL x, y, z;
        scanf("%ld %ld %ld", &x, &y, &z);
        double d = sqrt(x * x + y * y);
        double angle = atan2(y, x);
        if (angle < 0) angle = angle + 2 * M_PI;
        angle = M_PI / 2 - angle;
        if (angle < 0) angle += 2 * M_PI;
        Object tmp = {i, x, y, z, d, angle, false};
        objs[i] = tmp;
    }
    sort(objs + 1, objs + n + 1, cmp);
    int len = n;
    int k = 1;
    bool flag = false;
    do {
        flag = false;
        for (int i = 1; i <= len; i++) {
            if (objs[i].d <= L) {
                flag = true;
                sequence[objs[i].id] = k;
                L += objs[i].z;
                objs[i].st = true;
                if (i > len) break;
                int count = 1;
                if(i + 1 > len) {
                    k += count;
                    break;
                }
                while (objs[i+1].angle - objs[i].angle < 1e-6) {
                    if (objs[i+1].d <= L) {
                        sequence[objs[i+1].id] = k;
                        L += objs[i+1].z;
                        objs[i+1].st = true;
                        count++;
                    }
                    i++;
                    if(i + 1 > len) break;
                }
                k += count;
            }
        }
        int j = 1;
        for(int i = 1; i <= len; i++){
            if(!objs[i].st){
                backup[j++] = objs[i];
            }
        }
        len = j - 1;
        memcpy(objs,backup,sizeof objs);
    }while(flag);

    for (int i = 1; i <= n; i++) {
        if (sequence[i] != 0) printf("%d ", sequence[i]);
        else printf("%d ", -1);
    }
    return 0;
}