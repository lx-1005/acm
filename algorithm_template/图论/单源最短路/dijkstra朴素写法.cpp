
/*  dijkstra算法前提: 权重>=0
 *
 *  稀疏图（用邻居表）：m和n是一个数据级别, 用堆优化版dijkstra
 *  稠密图（用邻接矩阵）：m和n^2是一个数据级别，用朴素版dijkstra
 */

// 朴素算法O(n^2): 可以求某个起点到所有点的最短距离
#include <bits/stdc++.h>
using namespace std;

struct dijkstra {
    const int inf = 0x3f3f3f3f;
    int n; // 点数
    vector<vector<int>> g;

    dijkstra(int n, vector<vector<int>>& edges) : n(n) {
        // 建图: 初始化两点间无边
        g = vector<vector<int>>(n, vector<int>(n, inf));
        for (int i = 0; i < n; ++i) g[i][i] = 0;
        for (auto& e : edges) {
            int a = e[0], b = e[1], w = e[2]; // a->b的一条边，边权是w
            g[a][b] = min(g[a][b], w); // 防止重边和自环
        }
    }


    // d[i]表示start->i的最短距离, -1代表不可达
    void shortPath(int start) {
        vector<int> d(n, inf);
        d[start] = 0;
        vector<bool> st(n);

        while (1) { // 如果是连通图，会迭代n次，每次确定一个点的最短距离；否则起点所在的连通块都确定了最短路后，会退出循环
            int t = -1;
            for (int j = 0; j < n; ++j) { // 枚举[1~n]号点，找到还没确定最短路的点中距离起点最近的点t
                if (!st[j] && (t == -1 || d[j] < d[t])) t = j;
            }

            // 说明从起点到t号点不可达（代表这个图不是连通图，此时起点start所在的连通块内的点的最短距离都确定了，对于其他连通块的点，start是不可达的）
            if (t == -1 || d[t] == inf) break;
            st[t] = true; // t号点此时已经是最短距离

            //用起点到t号点的距离dist[t]， 去更新其余所有还未更新的点j与起点的最短距离st[j]
            // 这里不判断if(!st[j])也可以，毕竟st[]为true的点已经确定是最短了，也不会被继续更新了
            for (int j = 0; j < n; ++j) { // 尝试更新起点start到[1~n]号点的最短距离
                if (!st[j]) d[j] = min(d[j], d[t] + g[t][j]);
            }
        }
    }
};