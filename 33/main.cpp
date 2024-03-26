///https://www.acwing.com/problem/content/1072/
#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
const int N = 110;
int f[N][N];
bool is_match(char a,char b){
    if(a == '(' && b == ')'){
        return true;
    }
    if(a == '[' && b == ']'){
        return true;
    }
    return false;
}
int main(){
    string str;
    cin >> str;
    int len = str.size();
    for(int n = 1; n <= len; n++){
        for(int l = 0; l + n - 1 < len; l++){
            int r = l + n - 1;
            f[l][r] = INT_MAX;
            if(is_match(str[l],str[r])) f[l][r] = f[l+1][r-1];
            f[l][r] = min(f[l][r],min(f[l+1][r],f[l][r-1])+1);

            for(int k = l; k < r; k++){
                f[l][r] = min(f[l][r],f[l][k]+f[k+1][r]);
            }

        }

    }
    cout << f[0][len-1] << endl;
    return 0;
}