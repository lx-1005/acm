#ifndef HASH_PAIR_H
#define HASH_PAIR_H

#include <bits/stdc++.h>
using namespace std;


// 方法1:
// 使用: unordered_set<PII, pair_hash> s;
struct pair_hash { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ hash<T2>()(p.second); 
    } 
}; 


// 方法2: 用64位表示pair
哈希: h = (LL)(p.first << 32 | p.second)
恢复: p.first = h >> 32, p.seconmd = h >> 32 & UINT_MAX;

#endif


