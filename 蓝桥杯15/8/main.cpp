//
// Created by ldx on 24-4-19.
//
#include<iostream>
using namespace std;
int main(){
    srand((unsigned int)(time(nullptr)));
    int n;
    cin >> n;
    while(n--){
        int x =rand();
        if(x%2==0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }

    }
    return 0;
}