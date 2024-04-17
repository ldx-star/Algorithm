#include <iostream>

using namespace std;
typedef long long LL;
const int N = 10010;
int a[N];
int max_a[N];

int main() {
    // 请在此输入您的代码
    int n;
    cin >> n;
    int alys = 0;
    int k = 3 * n;
    bool flag = true;
    int count = 1;
    while (k--) {
//        cout << "day: " << count++ << "\t\t";
        for (int i = 0; i < n; i++) {
            a[i]++;
//            cout << a[i] << " ";
            if (max_a[i] < a[i]) {
                max_a[i] = a[i];
            }
        }
        if (flag) {
            a[alys++] = 0;
        }
        if (!flag) {
            a[alys--] = 0;
        }
        if (alys == n) {
            flag = false;
            alys -= 2;
        };
        if (alys == -1) {
            flag = true;
            alys += 2;
        }
//        cout << endl;
    }
//    cout << "================" << endl;
    for (int i = 0; i < n; i++) {
        cout << max_a[i] << endl;
    }
    return 0;
}