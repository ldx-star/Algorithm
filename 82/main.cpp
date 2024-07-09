#include <iostream>
using namespace std;

int main() {
    int a;
    char b;
    cin >> a >> b;
    int ans = 20;
    if(a <= 1){
        if(b == 'y'){
            return ans + 5;
        }else{
            return ans;
        }
    }else{
        a -= 1;
        ans += int(a);
        if(a - int(a) > 0.0000001){
            ans += 1;
        }
    }
    if(b == 'y'){
        return ans + 5;
    }else{
        return ans;
    }
}