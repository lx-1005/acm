

/*
 * 功能: 将数组a[x1][y1]~[x2][y2]范围内的每个数都加c, 求多次操作后的数组a[][]
 *
 *
 * 核心:
 *      1. a的差分数组b
 *      2. 对差分数组b求前缀和就能得到原数组a
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1010; // 数组的最大长度

int a[N][N], b[N][N], pre[N][N]; // 原数组a, a的差分数组b, b的前缀和pre
int n, m; // 数组长度n,
int q; // 区间操作q次

// a[x1][y1]~a[x2][y2] += c, 差分数组的等价操作
// 矩形区域左上角:[x1][y1] 右下角:[x2][y2]
void add(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c, b[x2 + 1][y1] -= c, b[x1][y2 + 1] -= c, b[x2 + 1][y2 + 1] += c;
}

int main() {
    cin >> n >> m >> q;
    // 原数组a
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x; cin >> a[i][j];
            add(i, j, i, j, a[i][j]);
        }
    }
    
    // a做q次范围+c操作, b需要做等价操作
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        add(x1, y1, x2, y2, c);
    }
    
    // 原数组a做若干次操作后变成pre
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + b[i][j];
            cout << pre[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
