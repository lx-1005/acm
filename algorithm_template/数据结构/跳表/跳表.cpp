
/*

支持：O(logn)完成增加、删除、查询

实现：
 只有最下面第0层保存节点值，同时为了搜索时跳的更快，新增第[1~maxLevel)层作为索引
 查询时，从上往下找，尽可能大步跳，如果再跳就跳多了，就往下一层
 插入时，从下往上依次插入，可以自定义概率，停止插入
 删除时，从下往上依次更新pre[i]->next[i]

*/
#include <bits/stdc++.h>
using namespace std;

class Skiplist {
    static const int maxLevel = 8; // 层数，经验值 8，太大浪费空间，因为每一个节点都要存在每一层的 next，层数越多节点数越多
    struct Node {
        int val; // 节点值
        vector<Node*> next; // next[i] 表示当前节点第 i 层的 next
        Node(int x = -1) : val(x) {
            next.resize(maxLevel, nullptr);
        }
    } *head; // 虚拟头

public:
    Skiplist() {
        head = new Node(-1); // 初始化一个不存在的节点值-1，因为题目保证插入的节点值>=0
    }

    ~Skiplist() {
        delete head;
    }

    vector<Node*> find(int x) { // 返回找x的过程中，每一层中<x的最大节点pre[i]
        vector<Node*> pre(maxLevel, nullptr);
        auto p = head;
        for (int i = maxLevel - 1; i >= 0; --i) {
            while (p->next[i] && p->next[i]->val < x) p = p->next[i];
            pre[i] = p;
        }
        return pre;
    }

    bool search(int target) { // 跳表中是否存在target
        auto pre = find(target);
        auto p = pre[0]->next[0];
        return p && p->val == target;
    }

    void add(int num) { // 插入元素num
        auto pre = find(num);
        auto node = new Node(num);
        for (int i = 0; i < maxLevel; ++i) {
            node->next[i] = pre[i]->next[i];
            pre[i]->next[i] = node;
            // 每一层有 50% 的概率不插入新节点
            // 如果写成 rand()%3==1，就是1/3的概率不插入新节点
            if (rand() % 2) break;
        }
    }

    bool erase(int num) { // 删除元素num
        auto pre = find(num);
        auto p = pre[0]->next[0];
        if (!p || p->val != num) return false; // 不存在

        for (int i = 0; i < maxLevel && pre[i]->next[i] == p; ++i) { // 自底向上删除
            pre[i]->next[i] = p->next[i];
        }
        delete p;

        return true;
    }
};