#include <iostream>
#include <algorithm>
using namespace std;
int r1[2],r2[2],r3[2];

int main()
{
    // 请在此输入您的代码
    int m;
    cin >> m;
    while(m--){
        int res = 8;
        cin >> r1[0] >> r1[1] >> r2[0] >> r2[1] >> r3[0] >> r3[1];
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    if(r1[i] == r2[j]){
                        if(r2[j] == r3[k]){
                            res = min(res,4) ;
                        }
                        if(r2[j] != r3[k]){
                            res = min(res,6) ;
                        }
                    }
                    if(r2[j] == r3[k]){
                        if(r1[i] == r3[k]){
                            res = min(res,4) ;
                        }
                        if(r1[i] != r3[k]){
                            res = min(res,6) ;
                        }
                    }
                    if(r1[i] == r3[k]){
                        if(r2[j] == r3[k]){
                            res = min(res,4) ;
                        }
                        if(r2[j] != r3[k]){
                            res = min(res,6) ;
                        }
                    }
                    if(r1[i] == r2[j] + r3[k]){
                        if(r2[1-j] == r3[1-k]){
                            res = min(res,4);
                        }else{
                            res = min(res,6);
                        }
                    }
                    if(r2[j] == r1[i] + r3[k]){
                        if(r1[1-i] == r3[1-k]){
                            res = min(res,4);
                        }else{
                            res = min(res,6);
                        }
                    }
                    if(r3[k] == r1[i] + r2[j]){
                        if(r1[1-i] == r2[1-j]){
                            res = min(res,4);
                        }else{
                            res = min(res,6);
                        }

                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}