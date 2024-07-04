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

int target = 0;
int ans = 0;
void preorder(TreeNode *root, pair<vector< int>,int> presum) {
    if (root == nullptr) {
        return;
    }

    if (presum.first.empty()) {
        presum.first.push_back(root->val);
    } else {
        presum.first.push_back(presum.first[presum.first.size() - 1] + root->val);
    }
    if (!presum.first.empty()) {
        int count = 0;
        for (int i = 0; i < presum.first.size(); i++) {
            for (int j = i + 1; j < presum.first.size(); j++) {
                if (presum.first[j] - presum.first[i] == target) {
                    count++;
                }
            }
        }
        ans += count - presum.second;
        presum.second = count;

    }
    preorder(root->left, presum);
    preorder(root->right, presum);
}

int pathSum(TreeNode *root, int targetSum) {
    pair<vector<int>,int> presum;
    presum.first.push_back(0);

    target = targetSum;
    preorder(root, presum);
    return ans;
}

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(-2);
    TreeNode *node3 = new TreeNode(-3);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(3);
    TreeNode *node6 = new TreeNode(-2);
    TreeNode *node7 = new TreeNode(-1);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node4->left = node7;

//    TreeNode *node1 = new TreeNode(1);
//    TreeNode *node2 = new TreeNode(2);
//    TreeNode *node3 = new TreeNode(3);
//    TreeNode *node4 = new TreeNode(4);
//    TreeNode *node5 = new TreeNode(5);
//    node1->left = node2;
//    node2->left = node3;
//    node3->left = node4;
//    node4->left = node5;
    pathSum(node1, 0);
}