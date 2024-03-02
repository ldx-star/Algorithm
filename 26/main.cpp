/// https://www.acwing.com/problem/content/1297/

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;
const int N = (1 << 20)+10;
LL fact(int x){
    LL res = 1;
    for(int i = x; i > 1; i--){
        res *= i;
    }
    return res;
}
int main()
{
    int x;
    vector<int> v;
    while(scanf("%d",&x) != -1)
    {
        v.clear();
        int sum = 0;
        for(int i = 2; i <= x / i; i++)
        {
            int s = 0;
            if(x % i == 0)
            {
                while(x % i == 0)
                {
                    x /= i;
                    s++;
                }
                sum += s;
                v.push_back(s);
            }
        }
        if(x > 1)
        {
            sum += 1;
            v.push_back(1);
        }
        LL tmp = 1;
        for(auto e : v){
            tmp = tmp * fact(e);
        }
        cout << sum << " " << fact(sum) / tmp <<  endl;

    }

    return 0;
}
