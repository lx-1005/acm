
/*
 *  稀疏图（用邻居表）：m和n是一个数据级别, 用堆优化版dijkstra
 *  稠密图（用邻接矩阵）：m和n^2是一个数据级别，用朴素版dijkstra
 */

// 朴素算法O(n^2): 可以求某个起点到所有点的最短距离
#include <bits/stdc++.h>
using namespace std;


const int inf = 0x3f3f3f3f; // 两点间的距离=inf时，表示不可达
const int N = 510, M = 1e5 + 10; // 点数N， 边数M
int n, m; // n个点，m条边
int g[N][N]; // 对于稠密图,用邻接矩阵; g[i][j]:表示边i->j的权重
int dist[N]; // dist[i]: 起点到i号点的最短距离
bool st[N]; // st[i]: 起点->i号点的最短距离是否确定

void build() { // 建图
    memset(g, 0x3f, sizeof g); //初始化图 因为求最短路 因此两点之间的距离初始化为无限大

    // 添加所有边
    cin >> n >> m;
    while (m--) {
        int a, b, w; // a->b的一条边，边权是w
        cin >> a >> b >> w;
        g[a][b] = min(g[a][b], w); //若发生重边，只保留权重最小的那条边(因为求的是最短路)
    }
}


// 求起点到所有点的最短距离dist[]，-1代表不可达
void dijkstra(int start) {
    memset(dist, 0x3f, sizeof dist); //初始化起点到所有点的距离为无限大，说明不可达
    dist[start] = 0; //起点到自身的距离为0

    while (1) { // 如果是连通图，会迭代n次，每次确定一个点的最短距离；否则起点所在的连通块都确定了最短路后，会退出循环
        int t = -1;
        for (int j = 1; j <= n; ++j) { // 枚举[1~n]号点，找到还没确定最短路的点中距离起点最近的点t
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        }

        // 说明从起点到t号点不可达（代表这个图不是连通图，此时起点start所在的连通块内的点的最短距离都确定了，对于其他连通块的点，start是不可达的）
        if (t == -1 || dist[t] == inf) break;
        st[t] = true; // t号点此时已经是最短距离

        //用起点到t号点的距离dist[t]， 去更新其余所有还未更新的点j与起点的最短距离st[j]
        // 这里不判断if(!st[j])也可以，毕竟st[]为true的点已经确定是最短了，也不会被继续更新了
        for (int j = 1; j <= n; ++j) { // 尝试更新起点start到[1~n]号点的最短距离
            if (!st[j]) dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == inf) dist[i] = -1;
    }
}


// 求指定起点start到指定终点end的最短距离，-1代表不可达
int dijkstra(int start, int end) { // 求start->end的最短距离，-1代表不可达
    memset(dist, 0x3f, sizeof dist); //初始化起点到所有点的距离为无限大，说明不可达
    dist[start] = 0; //起点到自身的距离为0

    while (true) { // 如果是连通图，会迭代n次，每次确定一个点的最短距离；否则起点所在的连通块都确定了最短路后，会退出循环
        int t = -1;
        for (int j = 1; j <= n; ++j) { // 从1号点开始，找到还没确定最短路的点中距离起点最近的点t
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        }

        // 说明从起点到t号点不可达（代表这个图不是连通图，此时起点start所在的连通块内的点的最短距离都确定了，对于其他连通块的点，start是不可达的）
        if (t == -1 || dist[t] == inf) break;

        st[t] = true; // t号点此时已经是最短距离
        if(t == end) break; // 已经找到了start->end的最短距离


        //用起点到t号点的距离dist[t]， 去更新其余所有还未更新的点j与起点的最短距离st[j]
        // 这里不判断if(!st[j])也可以，毕竟st[]为true的点已经确定是最短了，也不会被继续更新了
        for (int j = 1; j <= n; ++j) {
            if (!st[j]) dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    return dist[end] == inf ? -1 : dist[end];
}