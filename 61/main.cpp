//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/merge-intervals/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
struct Interval{
    int l,r;
};
static bool cmp(const Interval &a, const Interval &b){
    return a.r < b.r;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<Interval> v_intervals;
    for(auto inter : intervals){
        Interval tmp{inter[0],inter[1]};
        v_intervals.push_back(tmp);
    }
    sort(v_intervals.begin(), v_intervals.end(),cmp);
    vector<Interval> v_ans;
    for(int i = 0; i < v_intervals.size();i++){
        if(v_ans.empty()){
            v_ans.push_back(v_intervals[i]);
            continue;
        }else{
            v_ans.push_back(v_intervals[i]);
            while(v_ans.size() > 1){
                Interval &inter1 = v_ans[v_ans.size()-1];
                Interval &inter2 = v_ans[v_ans.size()-2];
                if(inter1.l > inter2.r){
                    break;
                }else if(inter1.l <= inter2.r && inter1.l >= inter2.l){
                    inter2.r = inter1.r;
                }else if(inter1.l < inter2.l){
                    inter2.l = inter1.l;
                    inter2.r = inter1.r;
                }
                v_ans.pop_back();
            }
        }

    }
    vector<vector<int>> res;
    for(int i = 0; i < v_ans.size();i++){
        vector<int> tmp;
        tmp.push_back(v_ans[i].l);
        tmp.push_back(v_ans[i].r);
        res.push_back(tmp);
    }
    return res;
}

int main() {
    vector<vector<int>> intervals;
    intervals.push_back({1, 3});
    intervals.push_back({2, 6});
    intervals.push_back({8, 10});
    intervals.push_back({15, 13});
    merge(intervals);
    return 0;
}