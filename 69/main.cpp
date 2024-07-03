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
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

void reverse(ListNode *&head){
    ListNode *newHead = new ListNode;
    while(head != nullptr){
        ListNode *tmp = head->next;
        head->next = newHead->next;
        newHead->next = head;
        head = tmp;
    }

    head = newHead->next;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *newHead = new ListNode;
    ListNode *cur = newHead;
    ListNode *p =head;
    while(p != nullptr){
        ListNode *tmpHead = p;
        ListNode *tmp = nullptr;
        for(int i = 0 ; i < k ; i++){
            if(p == nullptr){
                break;
            }
            if(i == k - 1){
                tmp = p->next;
                p->next = nullptr;
                break;
            }
            p = p->next;

        }
        if(p == nullptr){
            cur->next = tmpHead;
            break;
        }
        reverse(tmpHead);
        cur->next = tmpHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        p = tmp;
    }

    return newHead->next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode node1(2);
    ListNode node2(3);
    ListNode node3(4);
    ListNode node4(5);
    head->next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    reverseKGroup(head,2);
    return 0;
}