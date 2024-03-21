///https://www.acwing.com/problem/content/description/1228/
#include<iostream>
using namespace std;
const int N = 110;
int a[N];
int f[10010];

int gcd(int a,int b){
    return b ? gcd(b ,a % b) : a;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int g = a[1];
    for(int i = 2; i <= n; i++){
        g = gcd(g,a[i]);
    }
    if(g != 1){
        cout << "INF" << endl;
        return 0;
    }
    f[0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 10000; j++){
            if(f[j]) continue;
            for(int k = 1; k * a[i] <= j; k++){
                f[j] = f[j - k * a[i]];
                if(f[j]) break;
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= 10000; i++){
        if(!f[i]) res++;
    }
    cout << res << endl;
    return 0;
}