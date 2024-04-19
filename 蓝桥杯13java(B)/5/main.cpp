#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
LL fact[24];
map<int,int> m;
int check(LL x){
    int res = 0;
    while(x % 10 == 0){
        res++;
        x /= 10;
    }
    return res;
}
int main()
{
    // 请在此输入您的代码
    fact[0] = 1;
    for(int i = 1; i <= 20; i++){
        fact[i] = i * fact[i-1];
    }
    for(int i = 1; i <= 20; i++){
        if(i == 15){
            int a = 10;
        }
        int zero_num = check(fact[i]);
        if(m.count(zero_num)){
            if(m[zero_num] > i){
                m[zero_num] = i;
            }
        }else{
            m[zero_num] = i;
        }
    }
    for(int i = 0; i < 10; i++){
        if(m.count(i)){
            cout << "i: " << i << "\t" << m[i] << endl;
        }
    }
    return 0;
}