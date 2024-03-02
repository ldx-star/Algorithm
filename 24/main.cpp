/// https://www.acwing.com/problem/content/description/1250/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

typedef long long LL;
const int N = 3e5 + 10;
LL a[N];
LL s[N];
bool st[N];

int main() {

    int T;
    cin >> T;
    while (T--) {
        LL res = -1;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }
        LL s0 = s[0];
        LL sn = s[n];
        if (s0 > sn)swap(s0, sn);
        sort(s, s + n + 1);

        for (int i = 0; i <= n; i++) {
            if (s0 == s[i]) {
                s0 = i;
                break;
            }
        }
        for (int i = n; i >= 0; i--) {
            if (sn == s[i]) {
                sn = i;
                break;
            }
        }
        memset(st, 0, sizeof st);
        int l = 0, r = n;
        for (int i = s0; i >= 0; i -= 2) {
            a[l++] = s[i];
            st[i] = true;
        }
        for (int i = sn; i <= n; i += 2) {
            a[r--] = s[i];
            st[i] = true;
        }
        for (int i = 0; i <= n; i++) {
            if (!st[i]) {
                a[l++] = s[i];
            }
        }
        for (int i = 1; i <= n; i++) res = max(res, abs(a[i] - a[i - 1]));
        cout << res << endl;
    }


    return 0;
}