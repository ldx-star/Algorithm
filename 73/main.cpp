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

class DLink {
public:
    DLink() {
        val = 0;
        key = 0;
        pre = nullptr;
        next = nullptr;
    }

    DLink(int k,int v) {
        key = k;
        val = v;
        pre = nullptr;
        next = nullptr;
    }

    int key;
    int val;
    DLink *pre;
    DLink *next;
};

class LRUCache {
public:

    LRUCache(int capacity) {
        _cap = capacity;
        _head = new DLink();
        _tail = new DLink();
        _head->next = _tail;
        _tail->pre = _head;
    }

    int get(int key) {
        if(pos.find(key) == pos.end()){
            return -1;
        }
        DLink *tmp = pos[key];
        int ret = tmp->val;
        del(tmp);
        insert_tail(tmp);

        return ret;

    }

    void put(int key, int value) {
        if(pos.find(key) != pos.end()){
            DLink *tmp = pos[key];
            del(tmp);
            tmp->val = value;
            insert_tail(tmp);
        }else{
            _count++;
            DLink *tmp = new DLink(key,value);
            insert_tail(tmp);
            pos[key] = tmp;
            if(_count > _cap){
                delTop();
            }

        }
    }

    void insert_tail(DLink *list){
        _tail->pre->next = list;
        list->pre = _tail->pre;
        _tail->pre = list;
        list->next = _tail;
    }

    void del(DLink *&list) {
        list->pre->next = list->next;
        list->next->pre = list->pre;
    }
    void delTop(){
        _count--;
        DLink *tmp = _head->next;
        int key = tmp->key;
        pos.erase(pos.find(key));
        tmp->next->pre = _head;
        _head->next = tmp->next;
        tmp = nullptr;
    }

    int _cap;
    int _count = 0;

    DLink *_head;
    DLink *_tail;
    map<int, DLink *> pos;
};

int main() {
    LRUCache LRU(2);
    LRU.put(1, 0);
    LRU.put(2, 2);
    cout << LRU.get(1) << " ";
    LRU.put(3, 3);
    cout << LRU.get(2) << " ";
    LRU.put(4, 4);
    cout << LRU.get(1) << " ";
    cout << LRU.get(3) << " ";

    return 0;
}