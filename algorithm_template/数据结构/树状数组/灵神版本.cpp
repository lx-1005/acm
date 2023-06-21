#include <bits/stdc++.h>
using namespace std;

// 灵神版本: 下标从1开始
class Fenwick {
    vector<int> tree;

public:
    // 初始化：BIT f(n+1);  下标从1开始
    Fenwick(int n) : tree(n) {}
    
    // 目标：a[x]+=c
    // 用法：add(x+1, c)
    void add(int x, int c) {
        for (int i = x; i < tree.size(); i += i & -i) {
            tree[i] += c;
        }
    }
    
    // 目标：a[0~x-1]的和
    // 用法：sum(x)
    int query_sum(int x) {
        int ans = 0;
        for (int i = x; i; i -= i & -i) {
            ans += tree[i];
        }
        return ans;
    }
    
    // 目标：a[l~r]的和
    // 用法：sum(l+1, r+1)
    int query_sum(int l, int r) {
        return query_sum(r) - query_sum(l - 1);
    }
};