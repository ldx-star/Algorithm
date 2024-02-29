/// https://www.acwing.com/problem/content/description/114/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1010;
struct Node{
    float l, r;
    bool operator<(const Node& node)const{
        return r < node.r;
    }

}inter[N];
int main(){
    int n,d;
    cin >> n >> d;
    int k = 0;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        if(y > d){
            cout << -1;
            return 0;
        }
        float l = x - sqrt(d * d - y * y);
        float r = x + sqrt(d * d - y * y);
        inter[k++] = {l,r};
    }
    sort(inter,inter+k);
    float bound = 0 ;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            bound = inter[i].r;
            cnt++;
        }else{
            if(bound <= inter[i].r && bound >= inter[i].l) {
                continue;
            }
            if(bound < inter[i].l){
                bound = inter[i].r;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}