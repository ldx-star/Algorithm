///https://www.acwing.com/problem/content/1305/
#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
typedef long long LL;
const int N = 3;
int n,m;

void mul(int c[],int a[],int b[][N]){
    int temp[N] = {0};
    for(int i = 0; i < N; i++){
        temp[i] = ((LL)a[0] * b[0][i] + (LL)a[1] * b[1][i] + (LL)a[2] * b[2][i]) % m;

    }
    memcpy(c,temp,sizeof temp);
}
void mul(int c[][N],int a[][N],int b[][N]){
    int temp[N][N] = {0};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp[i][j] = ((LL)a[i][0] * b[0][j] + (LL)a[i][1] * b[1][j] + (LL)a[i][2]*b[2][j]) % m;

        }
    }
    memcpy(c,temp,sizeof temp);

}

int main(){
    cin >> n >> m;
    int A[N][N] = {
            {0,1,0},
            {1,1,1},
            {0,0,1}
    };
    int f1[N] = {1,1,1};
    n--;
    while(n){
        if(n&1) mul(f1,f1,A);
        mul(A,A,A);
        n >>= 1;
    }
    cout << f1[2] % m<< endl;
    return 0;
}