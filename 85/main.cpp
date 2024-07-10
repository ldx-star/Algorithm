#include <iostream>
#include <climits>

using namespace std;

const int N = 1e7 + 10;
int sum[N];

int main() {
    int n, x;
    cin >> n >> x;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
        if (idx == 0 && sum[i] >= x) {
            idx = i;
        }
    }
    int ans_l, ans_r, min_dist = INT_MAX;

    for (int l = 1, r = idx; l < r && r <= n;) {
        if (sum[r] - sum[l - 1] < x) {
            r++;
        } else {
            int dist = r - l;
            if (min_dist > dist) {
                min_dist = dist;
                ans_l = l;
                ans_r = r;
            }
            l++;
        }


    }
    cout << ans_l << " " << ans_r;
    return 0;
}