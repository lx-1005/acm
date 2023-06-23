

/*
 * 线段树: 维护"符合结合律的操作", 例如最值, 和, 异或和
 *
 *
 * 使用:
 *      1. 根据题目修改maxn
 *      2. 对seg.a[0~n-1]赋值
 *         build(1, 0, n-1)
 *      3. 根据需要修改或查询:
 *       区间修改: O(logn)
 *          modify()
 *       查询区间最大值, 最小值, 元素和: O(logn)
 *          query_mx()
 *          query_mn()
 *          query_sum()
 */

#include <bits/stdc++.h>
using namespace std;

struct SegTree {
private:
    using LL = long long;
    static constexpr int MAXN = 100010; // 根据题目调整
    int a[MAXN]; // 原数组a: 元素下标从0开始

    // 根节点: tr[1]
    inline int ls(int o){ return o << 1; }     // 左儿子
    inline int rs(int o){ return o << 1 | 1; } // 右儿子

    struct Node {
        int l, r; // 该节点掌管a[l~r]
        int mx, mn; // a[l, r]的元素最值
        LL sum;     // a[l, r]的元素和
        LL add;     // 懒标记
    } tr[MAXN * 4];

    // 将子节点的修改, 更新到父节点上
    void push_up(int o) {
        auto& root = tr[o], &l_son = tr[ls(o)], &r_son = tr[rs(o)];
        root.mx = max(l_son.mx, r_son.mx);
        root.mn = min(l_son.mn, r_son.mn);
        tr[o].sum = l_son.sum + r_son.sum;
    }

    // 将父节点的标记下传到两个儿子上
    void push_down(int o) {
        auto& root = tr[o], &l_son = tr[ls(o)], &r_son = tr[rs(o)];
        if (root.add) {
            l_son.add += root.add;
            l_son.mx += root.add;
            l_son.mn += root.add;
            l_son.sum += (LL)(l_son.r - l_son.l + 1) * root.add;

            r_son.add += root.add;
            r_son.mx += root.add;
            r_son.mn += root.add;
            r_son.sum += (LL)(r_son.r - r_son.l + 1) * root.add;

            root.add = 0;
        }
    }

public:
    // 建树: build(1, 0, n - 1);
    void build(int o, int l, int r) { // o: 当前节点, l和r: 节点o掌管的区间
        if (l == r) {
            tr[o] = {l, r, a[l], a[l], a[l], 0};
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

        push_down(o); // 先down完标记, 再做查询
        int mid = (tr[o].l + tr[o].r) >> 1;
        int mx = INT_MIN;
        if (L <= mid) mx = max(mx, query_mx(ls(o), L, R));
        if (R > mid) mx = max(mx, query_mx(rs(o), L, R));
        return mx;
    }

    // 查询a[L~R]的最小值: query(1, L, R);
    int query_mn(int o, int L, int R) {
        if (L <= tr[o].l && R >= tr[o].r) return tr[o].mn; // [l,r]完全包含[tr[o].l, tr[o].r]

        push_down(o); // 先down完标记, 再做查询
        int mid = (tr[o].l + tr[o].r) >> 1;
        int mn = INT_MAX;
        if (L <= mid) mn = min(mn, query_mn(ls(o), L, R));
        if (R > mid) mn = min(mn, query_mn(rs(o), L, R));
        return mn;
    }

    // 查询a[L~R]的元素和: query(1, L, R);
    LL query_sum(int o, int L, int R) {
        // [l,r]完全包含[tr[o].l, tr[o].r]
        if (L <= tr[o].l && R >= tr[o].r) return tr[o].sum;

        push_down(o); // 先down完标记, 再做查询
        int mid = (tr[o].l + tr[o].r) >> 1;
        LL s = 0;
        if (L <= mid) s += query_sum(ls(o), L, R);
        if (R > mid) s += query_sum(rs(o), L, R);
        return s;
    }

    // 修改a[l~r]+=x: modify(1, L, R, x)
    void modify(int o, int L, int R, int x) {
        if (L <= tr[o].l && R >= tr[o].r) {
            tr[o].mx += x;
            tr[o].mn += x;
            tr[o].sum += (LL)(tr[o].r - tr[o].l + 1) * x;
            tr[o].add += x; // 不在继续递归更新了
        } else {
            push_down(o); // 先down完标记, 再做修改
            int mid = (tr[o].l + tr[o].r) >> 1;
            if (L <= mid) modify(ls(o), L, R, x); // idx在左儿子
            if (R > mid) modify(rs(o), L, R, x); // idx在右儿子
            push_up(o); // 回溯时更新父节点
        }
    }
};