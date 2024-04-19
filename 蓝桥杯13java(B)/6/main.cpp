#include <iostream>
#include <fstream>
#include <cassert>

int s[21][21];
using namespace std;

int main() {
    // 请在此输入您的代码
    ifstream file("data.txt");
    assert(file.is_open());
    string line;
    int r = 1;
    while (getline(file, line)) {
        for (int i = 0; i < line.size(); i++) {
            int a = line[i] - '0';
            int col = i + 1;
            s[r][col] = a - s[r - 1][col - 1] + s[r - 1][col] + s[r][col - 1];
        }
        r++;
    }
    int max_val = 0;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            int r = i + 5 - 1;
            int c = j + 5 - 1;
            if (r <= 20 && c <= 20) {
                int ans = s[r][c] + s[i - 1][j - 1] - s[r][j - 1] - s[i - 1][c];
                if (ans > max_val) {
                    max_val = ans;
                }
            }
        }
    }
    cout << max_val;
    file.close();
    return 0;
}