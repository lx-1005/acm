/*
 * 功能: 将数组a[l, r]的每个数都加x, 求多次操作后的数组a[]
 *
 *
 * 核心:
 *      1. a[]的差分数组b: b[i]=a[i]-a[i-1]
 *      2. 对差分数组求前缀和就能得到原数组a
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1010; // 数组的最大长度
int a[N], b[N], pre[N]; // 原数组a, a的差分数组b, b的前缀和pre
int n, m; // 数组长度n, 区间操作m次

void insert_val(int l, int r, int c) { // a[l~r] += c, 差分数组的等价操作
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    cin >> n >> m;
    // 原数组a
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        insert_val(i, i, a[i]);
    }
    
    // m次区间a[l~r]+=c操作, b需要做等价操作
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert_val(l, r, c);
    }
    
    // 原数组a做若干次操作后变成pre
    pre[0] = b[0];
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + b[i];
    }
    for (int i = 0; i < n; ++i) cout << pre[i] << ' ';
}

