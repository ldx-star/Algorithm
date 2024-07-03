//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/symmetric-tree/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool check(const vector<int> arr){
    for(int i = 0, j = arr.size() - 1; j > i; i++,j--){
        if(arr[i] != arr[j]){
            return false;
        }
    }
    return true;
}
bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q_tree;
    vector<int> arr;
    q_tree.push(root);
    int last_layer = 1;
    int cur_layer = 0;
    while(!q_tree.empty()){
        auto front = q_tree.front();
        if(front == nullptr){
            q_tree.pop();
            last_layer--;
            arr.push_back(-111);
            if(last_layer == 0){
                last_layer = cur_layer;
                cur_layer = 0;
                bool ans = check(arr);
                if(ans == false){
                    return false;
                }
                arr.clear();
            }
            continue;
        }
        arr.push_back(front->val);

        q_tree.push(front->left);
        cur_layer++;

        q_tree.push(front->right);
        cur_layer++;

        q_tree.pop();
        last_layer--;
        if(last_layer == 0){
            last_layer = cur_layer;
            cur_layer = 0;
            bool ans = check(arr);
            if(ans == false){
                return false;
            }
            arr.clear();
        }
    }
    return true;
}

int main() {
    TreeNode* node1 =  new TreeNode(1);
    TreeNode* node2 =  new TreeNode(2);
    TreeNode* node3 =  new TreeNode(2);
    TreeNode* node4 =  new TreeNode(2);
    TreeNode* node5 =  new TreeNode(2);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node3->left = node5;

//    TreeNode* node1 =  new TreeNode(1);
//    TreeNode* node2 =  new TreeNode(2);
//    TreeNode* node3 =  new TreeNode(3);
//
//    node1->left = node2;
//    node1->right = node3;
    isSymmetric(node1);


    return 0;
}