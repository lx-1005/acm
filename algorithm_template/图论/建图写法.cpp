/*
 * 根据点数和边数建图, 有邻接表和邻接矩阵两种
 *  稠密图n^2 ≈ m: 邻接矩阵
 *  稀疏图n ≈ m: 邻接表
 */


#include <bits/stdc++.h>
using namespace std;

// 1. 灵神写法
// 邻接矩阵
void build1(int n, vector<vector<int>>& edges) { // 传入点数n和所有边edges
    vector<vector<int>> g(n, vector<int>(n));
    for (auto& e : edges) {
        // 无向边
        // 重边只保留权值最小的
        int a = e[0], b = e[1], c = e[2];
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }
}

// 邻接表
void build2(int n, vector<vector<int>>& edges) { // 传入点数n和所有边edges
    vector<vector<int>> g(n);
    for (auto& e : edges) {
        // 无向边
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
}




// 2. yxc写法
// 邻接矩阵
const int N = 510, M = 1e5 + 10; // 最大点数, 最大边数
int g[N][N];
void build1(int n, vector<vector<int>>& edges) {
    for (auto& e : edges) {
        // 无向边
        
        int a = e[0], b = e[1], c = e[2];
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }
}

// 邻接表
const int N = 1e5 + 10, M = 2 * N; // 点数, 边数（添加一条无向边， idx需要用两个数）
int h[N], e[M], w[M], ne[M], idx; // 邻接表
void add(int a, int b, int c) { // 添加边a->b， 权值为c
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void build2(int n, vector<vector<int>>& edges) {
    for (auto& e : edges) {
        // 无向边
        // 重边无所谓， 不影响?
        add(e[0], e[1], e[2]);
        add(e[1], e[0], e[2]);
    }
}

