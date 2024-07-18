#include <iostream>
#include <string>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    int mid = 0, mid1 = 0, mid2 = 0;
    if(total % 2 != 0){
        mid = (total / 2) + 1;
    }else{
        mid1 = total / 2;
        mid2 = mid1 + 1;
    }
    int mid1_val,mid2_val,mid_val;
    int i = 0,j = 0;
    int cnt = 0;
    while(i < nums1.size() && j <nums2.size()){
        while(i < nums1.size() && j <nums2.size() && nums1[i] <= nums2[j]){
            cnt++;
            if(mid && cnt == mid){
                mid_val =nums1[i];
            }
            if(mid1 && cnt == mid1){
                mid1_val = nums1[i];
            }
            if(mid2 && cnt == mid2){
                mid2_val = nums1[i];
            }
            i++;
        }
        while(i < nums1.size() && j <nums2.size() && nums1[i] > nums2[j]){
            cnt++;
            if(mid && cnt == mid){
                mid_val = nums2[j];
            }
            if(mid1 && cnt == mid1){
                mid1_val = nums2[j];
            }
            if(mid2 && cnt == mid2){
                mid2_val = nums2[j];
            }
            j++;
        }
    }
    while((cnt < mid || cnt < mid2) && i < nums1.size()){
        cnt++;
        if(mid && cnt == mid){
            return nums1[i];
        }
        if(mid1 && cnt == mid1){
            mid1_val = nums1[i];
        }
        if(mid2 && cnt == mid2){
            mid2_val = nums1[i];
        }
        i++;
    }
    while((cnt < mid || cnt < mid2) && j < nums2.size()){
        cnt++;
        if(mid && cnt == mid){
            return nums2[j];
        }
        if(mid1 && cnt == mid1){
            mid1_val = nums2[j];
        }
        if(mid2 && cnt == mid2){
            mid2_val = nums2[j];
        }
        j++;
    }
    if(mid1){
        return (mid1_val +mid2_val) / 2.0;
    }else{
        return mid_val;
    }
}
int main(){
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    findMedianSortedArrays(nums1,nums2);
    return 0;
}