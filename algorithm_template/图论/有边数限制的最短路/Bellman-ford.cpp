/*
 * Bellman-ford适用：限制边数的最短路，可以有负权边
 *
 */



#include <bits/stdc++.h>
using namespace std;

const int N = 510, M = 10010;
int n, m, k;
int d[N], backup[N]; // d[i]表示节点i到起点的距离，back[]是d[]的备份

struct Edge {
    int a, b, w;
}edges[M]; // 存每条边的起点、终点、权值

int bellman_ford() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    
    for (int i = 0; i < k; ++i) { // 限制k条边的最短路，外层就循环k次
        // 先备份一下d[]，防止发生串联影响
        // 即i=0，j=2时，拿d[1]更新了d[2]，紧接着j=3，可能会拿更新过的d[2]更新d[3]
        memcpy(backup, d, sizeof d);
        for (int j = 0; j < m; ++j) { // 遍历所有边
            auto v = edges[j];
            d[v.b] = min(d[v.b], backup[v.a] + v.w);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    
    bellman_ford();
    
    // 有些时候，可能一条路径会被若干条负权边更新，导致d[]<0x3f3f3f3f，通常我们认为+∞-x=+∞，但本题的写法不是真的+∞，而是被略微更新过的+∞
    // 题目限制边长<=1000，最多m条边，极限情况m条边的w=-1000，即-1e8，10亿-1亿=9亿，我们这里设置为>0x3f3f3f3f/2，用来表示被略微更新过的+∞
    if (d[n] > 0x3f3f3f3f / 2) puts("impossible");
    else cout << d[n] << endl;
    
    return 0;
}