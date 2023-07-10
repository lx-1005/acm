
/*
 * 堆优化版dijkstra: O(mlogn)
 *      稀疏图（用邻接表）：m和n是一个数据级别, 用堆优化版dijkstra
 *      稠密图（用邻接矩阵）：m和n^2是一个数据级别，用朴素版dijkstra
 */

#include <bits/stdc++.h>
using namespace std;

struct dijkstra {
    using PII = pair<int, int>;// <起点->该点的最短距离, 点的编号>
    const int inf = 0x3f3f3f3f;
    int n; // 点数
    vector<vector<PII>> g;

    dijkstra(int n, vector<vector<int>>& edges) : n(n) {
        // 建图: 初始化两点间无边
        g = vector<vector<PII>>(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1], w = e[2]; // a->b的一条边，边权是w
            g[a].push_back({b, w});
        }
    }

    // 求起点start->所有点的最短路距离dist[], -1表示表示不可达
    void shortPath(int start) {
        vector<int> d(n, inf);
        d[start] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> heap; // <start到节点的距离, 节点编号>
        heap.push({0, start}); // start号点的最短距离为0

        while (heap.size()) {
            auto [mn, u] = heap.top();
            heap.pop();

            for (auto& [v, w] : g[u]) { //遍历ver的所有出边
                if (d[v] > mn + w) { // start->v=start->u+u->v
                    //  用已经确定最短路的点u，更新u的邻居
                    d[v] = mn + w;
                    heap.push({d[v], v});
                }
            }
        }

        for (int i = 0; i < n; ++i) { // 所有从start不可达的点，距离我们设置为-1
            if (d[i] == inf) d[i] = -1;
        }
    }
};