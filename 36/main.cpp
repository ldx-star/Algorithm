///https://www.acwing.com/problem/content/description/1219/
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 6,mod = 1e9+7;
int get_pair[6] = {3,4,5,0,1,2};

void mul(int c[][N],int a[][N],int b[][N]){
    int temp[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp[i][j] = ((LL)a[i][0] * b[0][j] + (LL)a[i][1]* b[1][j] + (LL)a[i][2]* b[2][j]+ (LL)a[i][3]* b[3][j] + (LL)a[i][4]* b[4][j] + (LL)a[i][5]* b[5][j]) % mod;
        }
    }
    memcpy(c,temp,sizeof temp);
}


int main(){
    int n,m;
    cin >> n >> m;
    int A[N][N] = {
            {4,4,4,4,4,4},
            {4,4,4,4,4,4},
            {4,4,4,4,4,4},
            {4,4,4,4,4,4},
            {4,4,4,4,4,4},
            {4,4,4,4,4,4}
    };
    while(m--){
        int a,b;
        cin >> a >> b;
        a--,b--;
        A[a][get_pair[b]] = 0;
        A[b][get_pair[a]] = 0;
    }
    int f1[N][N] = {4,4,4,4,4,4};
    n--;
    while(n){
        if(n&1){
            mul(f1,f1,A);//F1 = F1 * A
        }
        mul(A,A,A);//A = A * A
        n >>= 1;
    }
    int res = 0;
    for(int i = 0; i < N; i++){
        res = (res + f1[0][i]) % mod;
    }
    cout << res << endl;
}