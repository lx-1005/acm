/*
 * 堆排序: 将数组a[]排序, 可以O(1)得到最小值/最大值
 *
 *
 *
 */


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10; // 待排序数组的最大长度
int n; // 数组长度
int a[N]; // 小顶堆

void down(int i) {
    int t = i;
    if (2 * i + 1 < n && a[2 * i + 1] < a[t]) t = 2 * i + 1;
    if (2 * i + 2 < n && a[2 * i + 2] < a[t]) t = 2 * i + 2;
    if (t != i) {
        swap(a[i], a[t]);
        down(t);
    }
}


void heap_sort() {
    // 排序
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = n / 2 - 1; i >= 0; --i) down(i);
    
    // 从小到大输出所有数
    int m = n;
    while (m--) {
        cout << a[0] << ' ';
        a[0] = a[n - 1];
        --n;
        down(0);
    }
}































