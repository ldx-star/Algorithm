#include <iostream>
#include <string>
#include <climits>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
int dp[10010];

int jump(vector<int>& nums) {
    memset(dp,0x3f3f3f,sizeof dp);
    dp[0] = 0;
    for(int i = 1; i < nums.size();i++){
        for(int j = i - 1; j >= 0; j-- ){
            if(j >= i - nums[j]){
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[nums.size() - 1];
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums);
    return 0;

}