/*
 * 手写unordered_set: 只支持插入数值类型; 对于字符串类型, 先得到哈希值, 就可以使用了
 *
 *  使用： 根据插入元素的个数，调节N
 *
 *  api:
 *      1. insert(x); 把数字x插入哈希表，若已存在就不插入
 *      2. find(x); 判断哈希表中是否存在x
 *      3. remove(x); 删除x， 若不存在就不操作
 */


#include <bits/stdc++.h>
using namespace std;


// C++11写法：
// 使用：根据插入元素总个数，调整base的值
class HASH_SET {
private:
    static const int base = 10001; // 桶数
    vector<list<int>> h; // 开链法
    
public:
    HASH_SET() {
        h.resize(base);
    }
    
    void insert(int x) { // 插入x
        int k = x % base;
        for (auto it = h[k].begin(); it != h[k].end(); ++it) {
            if (*it == x) return;
        }
        h[k].push_back(x);
    }
    
    bool find(int x) { // 查找key
        int k = x % base;
        for (auto it = h[k].begin(); it != h[k].end(); ++it) {
            if (*it == x) return true;
        }
        return false;
    }
    
    void remove(int x) { // 删除key， 若存在就删除， 不存在就不用操作
        int k = x % base;
        for (auto it = h[k].begin(); it != h[k].end(); ++it) {
            if (*it == x) {
                h[k].erase(it);
                return;
            }
        }
    }
};


// yxc写法：
// 使用：根据插入元素总个数，调整N的值
class HASH_SET {
private:
    static const int N = 100003; // 桶的个数N: 假如要放入哈希表中的数字个数为1e5, N要取>1e5的首个质数
    int h[N], e[N], ne[N], idx; // h[N]表示哈希表的N个桶，e[N]，ne[N]，idx实现单链表，idx使每一个节点地址对应一个唯一序号
    
public:
    HASH_SET() {
        memset(h, -1, sizeof h);
        idx = 0;
    }
    
    void insert(int x) { // 插入x: 相当于unordered_set, 若已存在就不插入了
        int k = (x % N + N) % N; // 插入位置
        
        // 若x存在就返回
        for (int i = h[k]; i != -1; i = ne[i]) {
            if (e[i] == x) return;
        }
        
        // 否则用头插法插入
        e[idx] = x, ne[idx] = h[k], h[k] = idx++;
    }
    
    bool find(int x) { // 判断哈希表中是否存在x
        int k = (x % N + N) % N;
        for (int i = h[k]; i != -1; i = ne[i]) {
            if (e[i] == x) return true; // 找到就返回
        }
        return false;
    }
    
    void remove(int x) { // 删除x, 若不存在就不操作
        int k = (x % N + N) % N;
        if (h[k] == -1) return; // 空的
        if (e[h[k]] == x) { // 删除首元素
            h[k] == ne[h[k]];
            return;
        }
        // 用待删元素的前一个位置删除
        int pre = h[k];
        for (int i = ne[h[k]]; i != -1; i = ne[i]) {
            if (e[i] == x) {
                ne[pre] = ne[i];
                return;
            }
            pre = i;
        }
    }
};