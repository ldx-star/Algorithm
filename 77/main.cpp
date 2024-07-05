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

TreeNode *ret = NULL;
bool lowestCommonAncestor_(TreeNode *root, TreeNode *p ,TreeNode *q){
    if(root == NULL){
        return false;
    }
    bool left = lowestCommonAncestor_(root->left,p,q);
    bool right = lowestCommonAncestor_(root->right,p,q);

    if(left && right){
        if(ret == NULL){
            ret = root;
        }
        return true;
    }
    if( (left||right) && (root == q || root == p )){
        if(ret == NULL){
            ret = root;
        }
        return true;
    }
    if(root == p || root == q){
        return true;
    }
    if(left || right){
        return true;
    }
    return false;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    lowestCommonAncestor_(root, p, q);
    return ret;
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
    cout << lowestCommonAncestor(node1,node2,node5)->val;
}