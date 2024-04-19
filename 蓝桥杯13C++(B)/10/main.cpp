#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

vector<unordered_set<ll> > hs;

int n;

ll ans, hei[N];

//对数据进行处理
ll justDoIt(ll x) {
    return sqrt(x/2 + 1);
}

int main() {

    cin>>n;
    hs.resize(n+1);

    for(int i = 1;i <= n;i++) {

        // x 表示第i-1根竹子的高度，我们要做的就是将其进行justDoIt处理直到高度等于1
        //同时，我们需要将i-1根竹子的处理过程记录下来，作为是否可以和下一根竹子一起处理的依据。
        //在处理的期间与第i-2根竹子的处理过程进行对比，如果在i-1根竹子的处理过程中出现和第i-2根竹子处理结果相同高度的情况，
        //说明可以和前一根竹子一起处理。
        ll x;
        cin>>x;

        while (x > 1) {
            //如果i-2根竹子的处理过程中不存在和x一样高的情况，则说明i-1根竹子的这次处理不能和i-2竹子一起，
            //因此处理次数+1，
            //如果出现了一样高的情况，再处理下去的情况同样会出现在hs[i-1]中，可以放心不会重复计数
            if(!hs[i-1].count(x)) ans++;

            //将x的处理过程储存，活用于下一次
            hs[i].insert(x);

            //处理x
            x = justDoIt(x);
        }
    }

    cout<<ans;
    return 0;
}
