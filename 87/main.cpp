#include <iostream>
#include <queue>

using namespace std;
const int N = 1e5 + 10;

int search(vector<int> &nums, int target) {
    if (nums.size() == 1) {
        if (target == nums[0]) {
            return 0;
        } else {
            return -1;
        }
    }
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (nums[mid] == target) {
            return mid;
        }
        // 判断那边是有序的
        if (mid - 1 == l || (mid - 1 >= 0 && nums[l] < nums[mid - 1])) {
            //左边有序
            int ll = l, rr = mid - 1;
            while (ll < rr) {
                int mmid = ll + rr + 1 >> 1;
                if (nums[mmid] > target) rr = mmid - 1;
                else ll = mmid;
            }
            if (nums[ll] == target) {
                return ll;
            } else {
                // 左边没有，去右边找
                l = mid;
            }
        } else {
            // 右边有序
            int ll = mid, rr = r;
            while (ll < rr) {
                int mmid = ll + rr + 1 >> 1;
                if (nums[mmid] > target) rr = mmid - 1;
                else ll = mmid;
            }
            if (nums[ll] == target) {
                return ll;
            } else {
                // 右边没有，去左边找
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 3, 5};
    search(nums, 1);

    return 0;
}