/*
 *
 * O(1)插入，查找，删除
 *
 * 使用： 根据插入元素的个数， 调整base值
 *
 * api:
 *      insert(x); 插入x，若已存在就不插入
 *      find(x);  查找x是否在哈希表中
 *      remove(x); 删除x， 若已存在就不操作
 */


#include <bits/stdc++.h>
using namespace std;

// C++11写法：
// 使用：根据插入元素总个数，调整base的值
class HASH_MAP {
public:
    vector<list<pair<int, int>>> hash; // 开链法
    int base = 10001; // 桶数
    HASH_MAP() {
        hash.resize(base);
    }
    
    void insert(int key, int value) { // 插入元素{key, value}
        int hashcode = key % base;
        for (auto it = hash[hashcode].begin(); it != hash[hashcode].end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        hash[hashcode].push_back({key, value});
    }
    
    int find(int key) { // 查找key对应的value值， 找不到就返回-1
        int hashcode = key % base;
        for (auto it = hash[hashcode].begin(); it != hash[hashcode].end(); ++it) {
            if (it->first == key) return it->second;
        }
        return -1;
    }
    
    void remove(int key) { // 删除key， 若存在就删除， 不存在就不用操作
        int hashcode = key % base;
        for (auto it = hash[hashcode].begin(); it != hash[hashcode].end(); ++it) {
            if (it->first == key) {
                hash[hashcode].erase(it);
                return;
            }
        }
    }
};

// yxc写法：
// 使用：根据插入元素总个数，调整N的值
class HASH_MAP {
public:
    static const int N = 10001;
    int h[N], ne[N], idx;
    pair<int, int> e[N];
    
    HASH_MAP() {
        memset(h, -1, sizeof h);
        idx = 0;
    }
    
    void insert(int key, int value) {
        int hashcode = key % 10001;
        for (int i = h[hashcode]; i != -1; i = ne[i]) {
            auto& p = e[i];
            if (p.first == key) { // 找到就修改
                p.second = value;
                return;
            }
        }
        // 找不到就插入
        e[idx] = {key, value};
        ne[idx] = h[hashcode];
        h[hashcode] = idx++;
    }
    
    int find(int key) {
        int hashcode = key % 10001;
        for (int i = h[hashcode]; i != -1; i = ne[i]) {
            auto p = e[i];
            if (p.first == key) { // 找到就修改
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hashcode = key % 10001;
        if (h[hashcode] == -1) return; // 空的
        if (e[h[hashcode]].first == key) { // 首个元素就是要删的
            h[hashcode] = ne[h[hashcode]];
            return;
        }
        // 记录前一个位置， 用于单链表删除
        int pre = h[hashcode];
        for (int i = ne[pre]; i != -1; i = ne[i]) {
            if (e[i].first == key) {
                ne[pre] = ne[i];
                return;
            }
            pre = i;
        }
    }
};