//
// Created by ldx on 24-4-23.
//
/// https://leetcode.cn/problems/intersection-of-two-linked-lists/?envType=study-plan-v2&envId=top-100-liked
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if(head->next == nullptr){
        return true;
    }
    ListNode *faster = head->next->next;
    ListNode *slower = head->next;
    ListNode *pre = head;
    while(faster != nullptr && slower != nullptr){
        faster = faster->next;
        if(faster == nullptr){
            break;
        }
        faster = faster->next;
        slower = slower->next;
        pre = pre->next;
    }
    pre->next = nullptr;
    faster = head;
    //逆置
    ListNode *newHead = new ListNode(0);
    while(slower != nullptr){
        ListNode *tmp = slower->next;
        slower->next = newHead->next;
        newHead->next = slower;
        slower = tmp;
    }
    slower = newHead->next;
    while(slower!=nullptr && faster != nullptr){
        if(faster->val != slower->val){
            return false;
        }
        slower = slower->next;
        faster = faster->next;
    }
    return true;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode node1(0);
    ListNode node2(3);
    ListNode node3(4);
    ListNode node4(0);
    ListNode node5(1);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    head->next = &node1;
    isPalindrome(head);
    return 0;
}