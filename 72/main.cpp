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

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge(ListNode *head1, ListNode *head2) {
    ListNode *ret = new ListNode;
    ListNode *cur = ret;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->val < head2->val){
            cur->next = head1;
            head1 = head1->next;
            cur = cur->next;
        }else{
            cur->next = head2;
            head2 = head2->next;
            cur = cur->next;
        }
    }
    if(head1 != nullptr){
        cur->next = head1;
    }
    if(head2 != nullptr){
        cur->next = head2;
    }
    return ret->next;
}

ListNode *sortList(ListNode *head) {
    if(head == nullptr){
        return nullptr;
    }
    int len = 0;
    ListNode *p = head;
    while (p != nullptr) {
        p = p->next;
        len++;
    }
    ListNode *ret = new ListNode(0);
    ListNode *cur = ret;

    for (int i = 1; i < len; i <<= 1) {
        while (head != nullptr) {
            ListNode *head1 = head;
            ListNode *head2 = nullptr;
            ListNode *p1 = head;
            for (int j = 1; j < i; j++) {
                if(p1 == nullptr){
                    break;
                }
                p1 = p1->next;
            }
            if(p1 != nullptr){
                head2 = p1->next;
                p1->next = nullptr;
            }
            ListNode *p2 = head2;
            for (int j = 1; j < i; j++) {
                if(p2 == nullptr){
                    break;
                }
                p2 = p2->next;
            }
            if(p2 != nullptr){
                head = p2->next;
                p2->next = nullptr;
            }
            cur->next = merge(head1, head2);
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            if(p2 == nullptr){
                break;
            }
        }
        head = ret->next;
        cur = ret;
    }
    return ret->next;
}

int main() {
    ListNode node0(4);
    ListNode node1(2);
    ListNode node2(1);
    ListNode node3(3);
    ListNode node4(5);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    sortList(&node0);
    return 0;
}