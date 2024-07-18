#include <iostream>
#include <string>
#include <climits>
#include <cstring>
using namespace std;

bool a[5010];
int LastRemaining_Solution(int n, int m) {
    // write code here
    memset(a,0,sizeof a);
    int remain = n;
    int start = -1;
    while(remain != 0){
        int count = 0;
        while(count < m ){
            start++;
            if(start >= n) {
                start = start % n;
            }
            if(a[start]){
                continue;
            }

            count++;
        }
//        if(start >= n) {
//            start = start % n;
//        }

        a[start] = true;
        remain--;
    }
    return start;
}
// 64 位输出请用 printf("%lld")
int main(){
    LastRemaining_Solution(5,3);

    return 0;
}