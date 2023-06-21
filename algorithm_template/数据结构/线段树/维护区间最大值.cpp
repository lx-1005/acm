
#include <bits/stdc++.h>
using namespace std;

// 单点修改, 查询区间最大值
static const int maxn = 200010; // 根据题目调整
#define ls(o) (o << 1)
#define rs(o) (o << 1 | 1)

struct Node {
    int l, r;
    int mx; // [l, r]的在最大值
} tr[maxn * 4];

//  将子节点的修改, 更新到父节点上
void pushup(int o) {
    tr[o].mx = max(tr[ls(o)].mx, tr[rs(o)].mx);
}

// 建树
void build(int o, int l, int r) {
    tr[o] = {l, r};
    if (l == r) return; // 叶子

    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
}

// 查询 [l, r] 的最值, 当前位于节点 o
int query(int o, int l, int r) {
    if (l <= tr[o].l && r >= tr[o].r) return tr[o].mx; // [l,r]完全包含[tr[o].l, tr[o].r]

    int mid = (tr[o].l + tr[o].r) >> 1;
    int mx = INT_MIN;
    if (l <= mid) mx = query(o << 1, l, r);
    if (r > mid) mx = max(mx, query(o << 1 | 1, l, r));
    return mx;
}

// 将下标idx处修改为val, 当前位于节点o
void modify(int o, int idx, int val) {
    if (tr[o].l == tr[o].r) tr[o].mx = val; // 找到 idx 了
    else {
        int mid = (tr[o].l + tr[o].r) >> 1;
        if (idx <= mid) modify(o << 1, idx, val); // idx在左儿子
        else modify(o << 1 | 1, idx, val); // idx在右儿子
        pushup(o); // 记得pushup
    }
}