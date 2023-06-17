
/*
 *  稀疏图（用邻接表）：m和n是一个数据级别, 用堆优化版dijkstra
 *  稠密图（用邻接矩阵）：m和n^2是一个数据级别，用朴素版dijkstra
 */

// 堆优化版dijkstra: O(mlogn)可以求某个起点到所有点的最短距离
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;// <起点->该点的最短距离, 点的编号>
const int inf = 0x3f3f3f3f; // 两点间的最短距离为inf，代表不可达
const int N = 150010, M = 150010; //点和边

int n, m;//点数和边数
int h[N], e[M], w[M], ne[M], idx; // 稀疏图用邻接表存储
int dist[N]; // dist[i]: 起点到i号点的最短距离
bool st[N]; // st[i]=true代表1->i的最短路经已经确定

void add(int a, int b, int c) { // 添加一条边a->b，边权为c
    //有重边也不要紧，只是堆中会有很多冗余边，但并不影响弹出
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void build(vector<vector<int>>& edges) { // 建图
    memset(h, -1, sizeof h); // 初始化图
    cin >> n >> m; // 点数，边数
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }
}

// 求起点start->所有点的最短路距离dist[]
void dijkstra(int start) { // 返回起点start到所有点的距离
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;//小根堆:之所以存点的距离和编号，因为要优先按距离从小到大排序，同时还需要知道是哪个点
    heap.push({0, start});//1号点的最短距离为0

    while (heap.size()) {
        auto t = heap.top();//取所有未确定最短路的点中距离最近的点
        heap.pop();

        int ver = t.second;
        if (st[ver]) continue;//说明ver点是冗余点
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) {//遍历ver的所有出边
            int j = e[i];// i只是个下标，e中在存的是i这个下标对应的点编号
            if (dist[j] > dist[ver] + w[i]) {//用ver更新所有ver邻接点的最短距离
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    for (int i = 1; i <= n; ++i) { // 所有从start不可达的点，距离我们设置为-1
        if (dist[i] == inf) dist[i] = -1;
    }
}