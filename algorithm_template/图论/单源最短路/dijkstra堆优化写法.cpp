
/*
 * 堆优化版dijkstra: O(mlogn)
 *      稀疏图（用邻接表）：m和n是一个数据级别, 用堆优化版dijkstra
 *      稠密图（用邻接矩阵）：m和n^2是一个数据级别，用朴素版dijkstra
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;// <起点->该点的最短距离, 点的编号>
const int inf = 0x3f3f3f3f;
int n; // 点数
vector<vector<PII>> g;

void build(vector<vector<int>>& edges) {
    // 建图: 初始化两点间无边
    g.resize(n);
    for (auto& e : edges) {
        int a = e[0], b = e[1], w = e[2]; // a->b的一条边，边权是w
        g[a].push_back({b, w});
    }
}

// 求起点start->所有点的最短路距离dist[], -1表示表示不可达
void dijkstra(int start) { // 返回起点start到所有点的距离
    vector<int> d(n, inf); // d[i]: 起点start->i的最短距离
    d[start] = 0;
    vector<bool> st(n); // st[i]: 标记节点是否已经确定d[i]
    
    priority_queue<PII, vector<PII>, greater<PII>> heap; // <start到节点的距离, 节点编号>
    heap.push({0, start}); // start号点的最短距离为0

    while (heap.size()) {
        auto [mn, u] = heap.top(); // 取所有未确定最短路的点中距离start最近的点u, 距离为mn
        heap.pop();
        
        if (st[u]) continue;
        st[u] = true;

        for (auto& [v, w] : g[u]) { //遍历ver的所有出边
            if (d[v] > d[u] + w) { // start->v=start->u+u->v
                d[v] = d[u] + w;
                heap.push({d[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) { // 所有从start不可达的点，距离我们设置为-1
        if (d[i] == inf) d[i] = -1;
    }
}