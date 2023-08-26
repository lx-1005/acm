
/*

支持：O(logn)完成增加、删除、搜索
跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。
*/
#include <bits/stdc++.h>
using namespace std;

class Skiplist {
public:
    static const int level = 8;

    struct Node {
        int val;
        vector<Node*> next;
        Node(int _val): val(_val) {
            next.resize(level, NULL);
        }
    }*head;

    Skiplist() {
        head = new Node(-1);
    }

    ~Skiplist() {
        delete head;
    }

    void find(int target, vector<Node*>& pre) {
        auto p = head;
        for (int i = level - 1; i >= 0; i -- ) {
            while (p->next[i] && p->next[i]->val < target) p = p->next[i];
            pre[i] = p;
        }
    }

    bool search(int target) {
        vector<Node*> pre(level);
        find(target, pre);
        auto p = pre[0]->next[0];
        return p && p->val == target;
    }

    void add(int num) {
        vector<Node*> pre(level);
        find(num, pre);
        auto p = new Node(num);
        for (int i = 0; i < level; i ++ ) {
            p->next[i] = pre[i]->next[i];
            pre[i]->next[i] = p;
            if (rand() % 2) break;
        }
    }

    bool erase(int num) {
        vector<Node*> pre(level);
        find(num, pre);

        auto p = pre[0]->next[0];
        if (!p || p->val != num) return false;

        for (int i = 0; i < level && pre[i]->next[i] == p; i ++ )
            pre[i]->next[i] = pjet->next[i];

        delete p;

        return true;
    }
};