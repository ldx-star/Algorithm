#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<string>> ans;
bool check(string str){
    if(str.size() == 1){
        return true;
    }
    for(int i = 0, j = str.size() - 1; i < j; i++ ,j--){
        if(str[i] != str[j]){
            return false;
        }
    }
    return true;
}
void partition_(string s, int len,vector<string> strs){

    if(len > s.size()){
        return;
    }
    string sub = s.substr(0,len);
    if(!check(sub)){
        return;
    }else{
        strs.push_back(sub);
        if(string(s.c_str() + len) == ""){
            ans.push_back(strs);
            return;
        }
        for(int i = 1; i <= s.size();i++){
            partition_(s.c_str() + len,i,strs);
        }
    }

}
vector<vector<string>> partition(string s) {
    vector<string> strs;
    for(int i = 1; i <= s.size();i++){
        partition_(s,i,strs);

    }
    return ans;

}
int main(){
    string s = "cdd";
    partition(s);
}