//
// Created by ldx on 24-2-2.
//
/// https://www.acwing.com/problem/content/1266/
#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int w[N];
struct Node {
    int l, r;
    int sum;
} tr[4 * N];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, w[r]};
    } else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)return tr[u].sum;
    else {
        int sum = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (mid >= l) {
            sum += query(u << 1, l, r);
        }
        if (mid < r) {
            sum += query(u << 1 | 1, l, r);
        }
        return sum;
    }
}

void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x)tr[u].sum += v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    build(1, 1, n);
    int k, a, b;
    while (m--) {
        cin >> k >> a >> b;
        if (k == 0) {
            cout << query(1, a, b) << endl;
        } else {
            modify(1, a, b);
        }
    }

    return 0;
}