

/*
 * 线段树: 维护"符合结合律的操作", 例如最值, 和, 异或和
 *
 *
 * 使用:
 *      1. 根据题目修改maxn和原数组a
 *      2. build(1, 0, maxn)建树
 *      3. 根据需要修改或查询:
 *       单点修改: O(logn)
 *          modify()
 *       查询区间最大值, 最小值, 元素和: O(logn)
 *          query_mx()
 *          query_mn()
 *          query_sum()
 */

#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int maxn = 200010; // 根据题目调整
vector<int> a(maxn); // 原数组a: 元素下标从0开始

// 根节点: tr[1]
inline int ls(int p){return p << 1;}     // 左儿子
inline int rs(int p){return p << 1 | 1;} // 右儿子

struct Node {
    int l, r; // 该节点掌管a[l~r]
    int mx, mn; // a[l, r]的元素最值
    LL sum;    // a[l, r]的元素和
} tr[maxn * 4];

//  将子节点的修改, 更新到父节点上
void push_up(int o) {
    auto& root = tr[o], &l_son = tr[ls(o)], &r_son = tr[rs(o)];
    root.mx = max(l_son.mx, r_son.mx);
    root.mn = min(l_son.mn, r_son.mn);
    tr[o].sum = l_son.sum + r_son.sum;
}

// 建树: build(1, 0, n - 1);
void build(int o, int l, int r) { // o: 当前节点, l和r: 节点o掌管的区间
    if (l == r) {
        tr[o] = {l, r, a[l], a[l], a[l]};
        return;
    }

    // 递归建树
    tr[o].l = l, tr[o].r = r;
    int mid = (l + r) >> 1;
    build(ls(o), l, mid);
    build(rs(o), mid + 1, r);
    // 在回溯时, 维护父节点信息
    push_up(o);
}

// 查询a[L~R]的最大值: query(1, L, R);
int query_mx(int o, int L, int R) {
    if (L <= tr[o].l && R >= tr[o].r) return tr[o].mx; // [l,r]完全包含[tr[o].l, tr[o].r]

    int mid = (tr[o].l + tr[o].r) >> 1;
    int mx = INT_MIN;
    if (L <= mid) mx = max(mx, query_mx(ls(o), L, R));
    if (R > mid) mx = max(mx, query_mx(rs(o), L, R));
    return mx;
}

// 查询a[L~R]的最小值: query(1, L, R);
int query_mn(int o, int L, int R) {
    if (L <= tr[o].l && R >= tr[o].r) return tr[o].mn; // [l,r]完全包含[tr[o].l, tr[o].r]

    int mid = (tr[o].l + tr[o].r) >> 1;
    int mn = INT_MAX;
    if (L <= mid) mn = min(mn, query_mn(ls(o), L, R));
    if (R > mid) mn = min(mn, query_mn(rs(o), L, R));
    return mn;
}

// 查询a[L~R]的元素和: query(1, L, R);
LL query_sum(int o, int L, int R) {
    if (L <= tr[o].l && R >= tr[o].r) return tr[o].sum; // [l,r]完全包含[tr[o].l, tr[o].r]

    int mid = (tr[o].l + tr[o].r) >> 1;
    LL s = 0;
    if (L <= mid) s += query_sum(ls(o), L, R);
    if (R > mid) s += query_sum(rs(o), L, R);
    return s;
}

// 修改a[idx]=x: modify(1, idx, x);
void modify(int o, int idx, int x) {
    if (tr[o].l == tr[o].r) tr[o].mx = tr[o].mn = tr[o].sum = x; // 找到 idx 了
    else {
        int mid = (tr[o].l + tr[o].r) >> 1;
        if (idx <= mid) modify(ls(o), idx, x); // idx在左儿子
        else modify(rs(o), idx, x); // idx在右儿子
        push_up(o); // 回溯时更新父节点
    }
}