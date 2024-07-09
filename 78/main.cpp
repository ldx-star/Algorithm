//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/path-sum-iii/?envType=study-plan-v2&envId=top-100-liked
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

vector<int> sum;
int preOrder(TreeNode *root){
    if(root == nullptr){
        return 0;
    }
    int left = preOrder(root->left);
    int right = preOrder(root->right);
    int num;
    if(left >= 0  && right >= 0){
        num = root->val + right + left;
    }else if(left >= 0){
        num = root->val + left;
    }else if(right >= 0){
        num = root->val + right;
    }else{
        num = root->val;
    }
    sum.push_back(num);

    if(left > 0 && left > right){
        return root->val + left;
    }else if(right >= 0 && left < right ){
        return root->val+right;
    }else{
        return root->val;
    }

}
int maxPathSum(TreeNode* root) {
    preOrder(root);
    int max_val = -2000;
    for(int e : sum){
        max_val = max(max_val,e);
    }
    return max_val;
}

int main() {
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(2);
    TreeNode *node5 = new TreeNode(4);
    node1->left = node2;
    node1->right = node3;
    node2->right = node4;
    node4->right = node5;
    cout << maxPathSum(node1);
}