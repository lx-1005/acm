/*
 * 树状数组模板：
 * ![image-20230501002342828](https://gcore.jsdelivr.net/gh/lx-1005/blog-img@main/images/202305010023876.png)
 *
 * 功能:
 *      单点修改: O(logn)
 *      求数组前缀和: O(logn)
 */

#include <bits/stdc++.h>
using namespace std;

// 张晴川版本: 下标从0开始
template<class T>
struct Fenwick : vector<T> { // [0, n)
    using S = vector<T>;
    int n;
    
    // 初始化: Fenwick<int> t(n);
    Fenwick(int _n = 0) : S(_n), n(_n) {}
    
    // 目标：重置为一个大小为m的新树状数组
    // 用法：t.clear(m)
    void clear(int m) {
        n = m;
        S::assign(n, T());
    }
    
    // 目标：a[x]+=c
    // 用法：add(x, c)
    void add(int x, T c) {
        for(; x < n; x |= x + 1) S::operator[](x) += c;
    }
    
    // 目标：a[0~x-1]的和
    // 用法：sum(x)
    inline T sum(int r) { // [0, r)
        T s = T();
        for(; r; r &= r - 1) s += S::operator[](r - 1);
        return s;
    }
    
    // 目标：a[l~r]的和
    // 用法：sum(l, r+1)
    T sum(int l, int r) { // [l, r)
        return sum(r) - sum(l);
    }
    
    // argmin_i x <= [0, i]
    int lower_bound(T x) {
        int i = 1, j = 0;
        T s = T();
        while(i < n) i <<= 1;
        for(; i; i >>= 1) {
            if(i + j <= n && s + S::operator[](i + j - 1) < x) {
                s += S::operator[](i + j - 1);
                j += i;
            }
        }
        return j;
    }
};