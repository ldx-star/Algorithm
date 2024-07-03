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

void merge_sort(ListNode *&head, int l, int r) {
    if (l >= r) {
        return;
    }
    ListNode *pre = nullptr;
    ListNode *post = nullptr;
    for (int i = 1; i < l; i++) {
        if (i == 1) {
            pre = head;
        } else pre = pre->next;
    }
    for (int i = 1; i <= r+1; i++) {
        if (i == 1) {
            post = head;
        } else post = post->next;
    }
    int mid = (l + r) / 2;
    merge_sort(head, l, mid);
    merge_sort(head, mid + 1, r);
    ListNode *p1 = nullptr;
    if(pre != nullptr){
        p1 = pre->next;
    }else{
        p1 = head;
    }
    ListNode *p2 = p1;
    for (int i = l; i <= mid; i++) {
        p2 = p2->next;
    }
    int count1 = 0;
    int count2 = 0;
    ListNode *newHead = new ListNode;
    ListNode *p = newHead;
    while (count1 < mid - l + 1 && count2 < r - mid) {
        if (p1->val < p2->val) {
            p->next = p1;
            p1 = p1->next;
            count1++;
        } else {
            p->next = p2;
            p2 = p2->next;
            count2++;
        }
        p = p->next;
    }
    while (count1 < mid - l + 1) {
        p->next = p1;
        p1 = p1->next;
        p = p->next;
        count1++;
    }
    while (count2 < r - mid) {
        p->next = p2;
        p2 = p2->next;
        p = p->next;
        count2++;
    }
    if (pre == nullptr) {
        head = newHead->next;
    } else {
        pre->next = newHead->next;
    }
    p->next = post;
}

ListNode *sortList(ListNode *head) {
    int len = 0;
    ListNode *p = head;
    while (p != nullptr) {
        p = p->next;
        len++;
    }
    merge_sort(head, 1, len);
    return head;
}

int main() {
    ListNode node0(4);
    ListNode node1(2);
    ListNode node2(1);
    ListNode node3(3);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    sortList(&node0);
    return 0;
}