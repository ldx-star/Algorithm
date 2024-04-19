#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int a[N];
int b[N];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    // 请在此输入您的代码
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n, cmp);
    int flag = n / 2;
    if (n % 2 != 0) {
        flag += 1;
    }
    int bigger = 0;
    int lower = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[flag - 1]) bigger++;
        if (a[i] < b[flag - 1]) lower++;
    }

    for (int i = 0; i < n; i++) {
        if (b[flag - 1] == a[i]) cout << 0 << " ";
        else if (lower <= bigger) {
            int dif = b[flag - 1] + 1 - a[i];
            if (dif <= 0) cout << 0 << " ";
            else cout << dif << " ";
        } else {
            int dif = b[flag - 1] - a[i];
            if (dif <= 0) cout << 0 << " ";
            else cout << dif << " ";
        }
    }
    return 0;
}