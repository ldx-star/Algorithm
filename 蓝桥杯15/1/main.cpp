//
// Created by ldx on 24-4-18.
//
#include <iostream>

using namespace std;

bool check(int x){
    bool flag = false;
    while(x){
        if(x % 2 == 0 && flag == false){
            return false;
        }
        if(x % 2 != 0 && flag == true){
            return false;
        }
        x /= 10;
        flag = (!flag);
    }
    return true;

}

int main() {
    int n;
    cin >> n;
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(check(i)){
            count++;
        }
    }
    cout << count;
    return 0;
}