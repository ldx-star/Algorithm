///https://www.acwing.com/problem/content/1224/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1010;
char s[N];
int f[N][N];
int main(){
    scanf("%s",s);
    int len = strlen(s);
    for(int i = 1; i <= len; i++){
        for(int j = 0; j + i - 1  < len; j++ ){
            int l = j;
            int r = j + i - 1;
            if(i == 1)f[l][r] = 1;
            else{
                if(s[l] == s[r]) f[l][r] = f[l+1][r-1] + 2;
                if(f[l][r-1] > f[l][r]) f[l][r] = f[l][r-1];
                if(f[l+1][r] > f[l][r]) f[l][r] = f[l+1][r];
            }
        }
    }
    cout <<len - f[0][len-1] << endl;
    return 0;
}