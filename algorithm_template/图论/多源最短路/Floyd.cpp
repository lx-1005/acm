


/*
 * 多源最短路：O(n^3) 求任意两个节点i->j的最短距离d[i][j]
 *          if (d[i][j] > inf / 2) 说明i->j不可达
 */



#include <bits/stdc++.h>
using namespace std;

const int N = 210; // 最大点数
const int INF = 1e9;
int n, m; // 点数，边数
int d[N][N]; // d[i][j]: i号点->j号点的最短距离

void build() { // 建图
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    while (m--) { // 添加边a->b，权值为w
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        d[a][b] = min(d[a][b], w);
    }
}


// 求任意两个节点i和j间的最短距离d[][]
// if (d[i][j] > inf / 2) 说明i->j不可达
void floyd() {
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}