//
// Created by ldx on 24-4-18.
//
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> mul(vector<int> A, int B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        int a = A[i];
        int ans = a * B + t;
        t = ans / 10;
        C.push_back(ans % 10);
    }
    if (t != 0) {
        C.push_back(t);
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    int n;
    string d;
    cin >> n >> d;
    // 先判断小数的位数
    int dig = 0;
    vector<int> A;

    for(int i = d.size()-1; i >= 0; i--){
        if(d[i] == '.'){
            dig = d.size()-1-i;
            continue;
        }
        A.push_back(d[i] -'0');
    }

    for (int i = 0; i < n; i++) {
        A = mul(A, 2);
    }
    int f = A[dig-1];
    if (f >= 5) {
        int t = 0;
        int i = dig;
        A[i] += 1;
        if (A[i] >= 10) {
            t = 1;
            A[i] %= 10;
        }
        while (t) {
            i++;
            A[i] = A[i] + t;
            t = A[i] / 10;
            A[i] = A[i] % 10;
        }

    }
    for (int i = A.size() - 1; i >= dig; i--) {
        cout << A[i];
    }
    return 0;
}