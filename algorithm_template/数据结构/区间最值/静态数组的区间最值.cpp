
/*

考虑一个长为n的数组a[], 查询若干次a[l, r]的最大值, 在查询期间不会修改数组a
 
 1. 预处理以a[i]开始, 长为2的幂所有子数组的最值, 需要O(nlogn)
 2. 每次查询只需O(1)
 
*/



#include <bits/stdc++.h>
using namespace std;

// 预处理: O(nlogn) 以最大值为例
vector<int> a(n);
vector<vector<int>> mx(n, vector<int>(n + 1), INT_MIN); // mx[i][j]: a[i~i+j-1]的最大值
for (int i = 0; i < n; ++i) mx[i][1] = a[i];
for (int len = 2; len <= n; len *= 2) {
    for (int l = 0; l <= n - len; ++l) {
        // [l~l+len-1] -> [l, l+len/2-1]和[l+len/2, l+len-1]
        mx[l][len] = max(m[l][len / 2], m[l + len / 2[len / 2]);
    }
}

// 查询: O(1)
int query(int l, int r) {
    int len = r - l + 1;
    int t = 1; // 不超过len的最大的2的幂
    while (1) {
        t <<= 1;
        if (t > len) {
            t >>= 1;
            break;
        }
    }
    // [l~r] -> [l, l+t-1]和[r-t+1~r]
    return max(mx[l][t], mx[r - t + 1][t]);
}