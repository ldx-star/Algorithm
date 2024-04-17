#include <iostream>

using namespace std;
const int N = (1 << 20) + 10;
int last[N];
int a[N];
int f[N];

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        f[i] = max(f[i - 1], last[tmp ^ x]);
        last[tmp] = i;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (f[r] >= l)cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
