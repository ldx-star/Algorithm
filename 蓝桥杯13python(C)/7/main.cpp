#include <iostream>
using namespace std;
typedef pair<int,int> PII;
int d_x[6] = {-1,-1,1,1,1,-1};
int d_y[6] = {0,-1,-1,0,1,1};

PII get_position(int d,int p,int q){
    PII O = {0,0};
    for(int i = 0; i < p; i++){
        O.first = O.first + d_x[d];
        O.second = O.second + d_y[d];
    }
    for(int i = 0; i < q; i++){
        O.first = O.first + d_x[(d+2) % 6];
        O.second = O.second + d_y[(d+2) % 6];
    }
    return O;
}

int main()
{
    // 请在此输入您的代码
    int d1,p1,q1,d2,p2,q2;
    cin >> d1 >> p1 >> q1 >> d2 >> p2 >> q2;
    PII A = get_position(d1,p1,q1);
    PII B = get_position(d2,p2,q1);
    return 0;
}