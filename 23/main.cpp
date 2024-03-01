/// https://www.acwing.com/problem/content/description/1249/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long LL;
const int N = 2 * 1e5+10;
int a[N];
int main(){
    int n,m;
    cin >> n >> m;
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    int max_idx ,min_idx;
    int sum = 0;
    for(int i = 0; i < m + n + 1 ; i++){
        cin >> a[i];
        sum += a[i];
        if(a[i] < min_val){
            min_val = a[i];
            min_idx = i;
        }
        if(a[i] > max_val){
            max_val = a[i];
            max_idx = i;
        }
    }
    LL res = 0;
    if(m == 0){
        res = sum;
    }else{
        for(int i = 0; i < m + n + 1; i++){
            if(i == max_idx || i == min_idx) continue;
            res += abs(a[i]);
        }
        res = res + max_val - min_val;
    }
    cout << res;

    return 0;
}