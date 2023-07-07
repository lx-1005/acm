
/*
 * 多源最短路：O(n^3) 求任意两个节点i->j的最短距离d[i][j]
 */


#include <bits/stdc++.h>
using namespace std;

class Folyd {
    int n; // 点数
    vector<vector<int>> d;
public:
    Folyd(int n, vector<vector<int>> &edges) {
        // 邻接矩阵（初始化为无穷大，表示 i 到 j 没有边）
        d = vector<vector<int>>(n, vector<int>(n, INT_MAX / 3));
        for (int i = 0; i < n; ++i) d[i][i] = 0;
        for (auto &e: edges) {
            int a = e[0], b = e[1], w = e[2];
            d[a][b] = min(d[a][b], w); // 防止重边和自环
        }
        
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    
    void addEdge(vector<int> e) { // 添加一条边
        int a = e[0], b = e[1], w = e[2];
        if (w >= d[a][b]) return; // 无需更新
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][a] + w + d[b][j]); // i->j=i->a+a->b+b->j
    }
    
    int shortestPath(int start, int end) { // 返回start -> end 的最短路长度, 若不可达返回-1
        int ans = d[start][end];
        return ans < INT_MAX / 3 ? ans : -1;
    }
};