#include <iostream>
#include <queue>
#include<climits>
using namespace std;
const int N = 1e5 + 10;

void binary(vector<int>& nums, int l ,int r,int &min_val){
    if(l > r){
        return;
    }
    if(l == r){
        min_val = min(min_val,nums[l]);
        return;
    }
    if(l < r){
        int mid = l + r + 1>> 1;
        if(l == mid-1 || nums[l] < nums[mid - 1]){
            //左边有序
            min_val = min(min_val,nums[l]);
            binary(nums,mid,r,min_val);
        }else{
            // 右边有序
            min_val = min(min_val,nums[mid]);
            binary(nums,l,mid-1,min_val);
        }
    }
}
int findMin(vector<int>& nums) {
    int min_val = INT_MAX;
    int l = 0, r = nums.size()-1;
    binary(nums,l,r,min_val);
    return min_val;
}
int main() {
    vector<int> nums = {2,3,1};
    findMin(nums);

    return 0;
}