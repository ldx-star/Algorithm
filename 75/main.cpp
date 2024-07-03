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
int preVal =;
bool isValidBST(TreeNode* root) {
    if(root == nullptr){
        return true;
    }
    bool leftBST = isValidBST(root->left);
    if(!leftBST){
        return false;
    }
    if(preVal >= root->val){
        return false;
    }
    preVal = root->val;
    return isValidBST(root->right);
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