#include <iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int a[N];
LL sum_a[N];
int b[N];
int c[N];

void add(int l, int r) {
    b[l] += 1;
    b[r + 1] -= 1;
}

int main() {
    // 请在此输入您的代码
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum_a[i] = sum_a[i - 1] + a[i];
    }
    int m;
    cin >> m;
    LL sum_origin = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        sum_origin += sum_a[r] - sum_a[l - 1];
        add(l, r);
    }
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + b[i];

    }
    sort(a + 1, a + n + 1);
    sort(c + 1, c + 1 + n);
    LL sum_changed = 0;
    for (int i = 1; i <= n; i++) {
        sum_changed += c[i] * a[i];
    }
    cout << sum_changed - sum_origin << endl;
    return 0;
}