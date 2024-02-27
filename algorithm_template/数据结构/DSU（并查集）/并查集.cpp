/*

并查集：近乎o(1)实现（合并两集合 / 查询两元素是否在同一集合）*

原理：每个集合用一棵树表示，树根的编号代表整个集合的编号。每个节点存储它的父节点，即x的父节点为father[x]
1. 判断某节点是否是树根：当father[x] == x时，x就是树根
2. 求节点x的集合编号：while (fa[x] != x) x = fa[x];
3. 合并两个集合x,y：fa[x] = y; // 从集合y中随便选一个节点，作为整个集合x的爹

优化：
1. 路径压缩（老祖宗变成爹）：在查过x节点的集合编号后，就把x到树根路径上所有节点都直接连到树根(即father[路径每个节点]=树根)
2. 按秩合并（作用不大）

*/

/*
    api:
        find(x); 返回x的祖宗节点 + 路径压缩
        merge(a, b); 合并a，b元素所在的两个集合
        query(a, b); 查询两个元素是否在同一集合
        count(x); 查询x所在集合的元素个数
        
    使用：
        1. 先根据题意初始化
        2. 使用find(), query(), merge(),count()解题
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10; // 元素
int fa[N]; // fa[i]: 元素i的父亲
int sz[N]; // sz[i]: 元素i所在集合的元素数目, 只有i是祖宗时sz[i]才有意义

// 初始化
void init() {
    // 初始每个节点都是树根，即每个节点各自为一个集合
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        sz[i] = 1;
    }
}

// 返回x的祖宗节点 + 路径压缩
int find(int x) {
    // x和father[x]的祖宗是同一个
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

// 查询两元素a，b是否在同一集合
bool query(int a, int b) {
    return find(a) == find(b); // 判断a和b是不是同一个祖宗
}

// 合并a，b集合
void merge(int a, int b) {
    if (query(a, b)) return; // 已经在一个集合了
    int aa = find(a), bb = find(b);
    fa[aa] = bb;
    sz[bb] += sz[aa];
}

// 返回x所在集合的元素个数
int count(int x) {
    return sz[find(x)];
}

// jiangly模板
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};