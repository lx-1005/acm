#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key, value, freq;

    Node(int k, int v, int f) : key(k), value(v), freq(f) {}
};

class LFUCache {
private:
    int capacity, minFreq; // capacoty表示缓存容量, minFreq用于缓存满时删除节点使用
    unordered_map<int, list<Node>::iterator> key_cache; // <key, list<Node>::iterator>, 根据key查出节点在freq_cache中的位置
    unordered_map<int, list<Node>> freq_cache;          // <freq, list>, 每个freq下放着一个双向链表（全是访问频数为freq的节点，且头结点是最新访问的，因此不需要专门记录time）

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {
        freq_cache.clear();
        key_cache.clear();
    }
    
    int get(int key) { // 读操作
        if (!capacity) return -1;

        auto it = key_cache.find(key);
        if (it == key_cache.end()) return -1; // 没找到

        // 找到了：由于新读了一次，因此node节点就不在freq这个桶下了，需要放到freq+1这个桶下
        auto node = it->second;
        int value = node->value, freq = node->freq;
        freq_cache[freq].erase(node); 
        
        // 如果node是freq频数下的唯一节点，就要把对应list删了, 并且更新minFreq
        if (freq_cache[freq].size() == 0) {
            freq_cache.erase(freq);
            if (freq == minFreq) minFreq += 1; // 这里即便freq下一个频数不是freq+1，但下面要在freq+1插入一个节点，因此这里一定可以这样更新
        }

        // 插到freq+1中
        freq_cache[freq + 1].push_front({key, value, freq + 1}); // 作为freq+1内的最先访问的节点
        key_cache[key] = freq_cache[freq + 1].begin();

        return value;
    }
    
    void put(int key, int value) {
        if (!capacity) return;

        auto it = key_cache.find(key);
        if (it == key_cache.end()) { // 没找到就插入一个
            if (capacity == key_cache.size()) { // 缓存满了就要踢一个
                auto delnode = freq_cache[minFreq].back();
                key_cache.erase(delnode.key);
                freq_cache[minFreq].pop_back();
                if (freq_cache[minFreq].size() == 0) freq_cache.erase(minFreq);
                // 这里不用更新minFreq, 因为要新插入一个节点，因此minFreq一定更新为1
            }
            freq_cache[1].push_front(Node{key, value, 1});
            key_cache[key] = freq_cache[1].begin();
            minFreq = 1;
        }
        else { // 找到了就更新value
            auto node = it->second;
            int freq = node->freq;
            freq_cache[freq].erase(node);

            if (freq_cache[freq].size() == 0) {
                freq_cache.erase(freq);
                if (freq == minFreq) minFreq = freq + 1;
            }

            freq_cache[freq + 1].push_front(Node{key, value, freq + 1});
            key_cache[key] = freq_cache[freq + 1].begin();
        }
    }
};