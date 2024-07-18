#include <iostream>
#include <string>
#include <climits>
using namespace std;

int max_score = INT_MIN;

void cal(string str) {
    int score = 0;
    for (int i = 0 ; i < str.size() - 2;i++) {
        string sub1 = str.substr(i, 3);
        string sub2 = str.substr(i, 2);
        if (sub1 == "you") {
            score += 2;
        }
        if (sub2 == "oo") {
            score += 1;
        }
    }
    max_score = max(score,max_score);
}

void dfs(string str, char ch, int a, int b, int c) {
    str += ch;
    if (a == 0 && b == 0 && c == 0) {
        cal(str);
    }
    if (a) {
        dfs(str, 'y', a-1, b, c);
    }
    if (b) {
        dfs(str, 'o', a, b-1, c);
    }
    if (c) {
        dfs(str, 'u', a, b, c-1);
    }
}

void youyou(int a, int b, int c) {
    string str;
    if (a) {
        dfs(str, 'y', a-1, b, c);
    }
    if (b) {
        dfs(str, 'o', a, b-1, c);
    }
    if (c) {
        dfs(str, 'u', a, b, c-1);
    }
}

int main() {
    int n;
    cin >> n;
    int a, b, c;
    while (n--) {
        cin >> a >> b >> c;
        youyou(a, b, c);
        cout << max_score << endl;
    }
    return 0;

}
// 64 位输出请用 printf("%lld")