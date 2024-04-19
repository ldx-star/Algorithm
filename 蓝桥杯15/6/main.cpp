//
// Created by ldx on 24-4-19.
//
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<fstream>
#include<string>

using namespace std;
const int N = 2e5 + 10;
typedef pair<int, int> PII;
PII a[N];

bool cmp(PII p1, PII p2) {
    if(p1.second != p2.second) return p1.second < p2.second;
    else return p1.first < p2.first;
}

int dig[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int func(int x) {
    int count = 0;
    while (x) {
        count += dig[x % 10];
        x /= 10;
    }
    return count;
}

int main() {
    int n = 2000;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int num;
//        scanf("%d", &num);
        a[i].first = num;
    }
    for (int i = 0; i < n; i++) {
        a[i].second = func(a[i].first);
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i].first);
    }
    return 0;
}
