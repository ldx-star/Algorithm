//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/reverse-nodes-in-k-group/submissions/541975880/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        Node *copyNode = new Node(cur->val);
        copyNode->next = cur->next;
        Node *tmp = cur->next;
        cur->next = copyNode;
        cur = tmp;

    }
    cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->random == NULL) {
            cur->next->random = NULL;
        } else {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;

    }
    Node *ret = head->next;
    cur = head;
    Node *retCur = ret;
    while (cur != NULL) {
        Node *tmp = retCur->next;
        if (tmp == NULL) {
            cur->next = NULL;
            break;
        }
        cur->next = tmp;
        retCur->next = tmp->next;
        cur = cur->next;
        retCur = retCur->next;
    }
    return ret;
}

int main() {
    Node node0(7);
    Node node1(13);
    Node node2(11);
    Node node3(10);
    Node node4(1);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node0.random = NULL;
    node1.random = &node0;
    node2.random = &node4;
    node3.random = &node2;
    node4.random = NULL;
    copyRandomList(&node0);
    return 0;
}