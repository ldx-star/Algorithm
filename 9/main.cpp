//
// Created by ldx on 24-2-22.
//
///https://www.acwing.com/problem/content/1240/
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5+10;
int cnt[N];
PII logs[N];
bool st[N];
int main(){
    int n,d,k;
    cin >> n >> d >> k;
    for(int i = 0; i < n;i++){
        int ts, id;
        cin >> ts >> id;
        logs[i].first = ts;
        logs[i].second = id;
    }
    sort(logs,logs+n);
    for(int i = 0, j = 0; i < n; i++){
        int id = logs[i].second;
        cnt[id]++;
        while(logs[i].first - logs[j].first >= d){
            cnt[logs[j].second]--;
            j++;
        }
        if(cnt[id] > k) st[id] = true;
    }
    for(int i = 0; i < N; i++){
        if(st[i] == true){
            cout << i << endl;
        }
    }


    return 0;
}