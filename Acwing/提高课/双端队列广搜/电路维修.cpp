#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;

const int N = 510;
char cs[] = "\\/\\/"; // '\'是转义字符,所以'\\'表示'\'
int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1}; //左上 右上 右下 左下
int ix[] = {-1, -1, 0, 0}, iy[] = {-1, 0, 0, -1}; //电路存在方格左上角的点上 分别对应左上 右上 右下 左下

int n, m;
char g[N][N];
int dis[N][N];
bool st[N][N];


int bfs() {
    memset(st, 0, sizeof st);
    memset(dis, 0x3f, sizeof dis);
    dis[0][0] = 0;
    deque<PII> dq;
    dq.push_back({0, 0});
    while (dq.size()) {
        auto [x, y] = dq.front(); 
        dq.pop_front();

        // 每个点可能会被扩展多次，第一次被扩展到的时候不一定是最优解。
        // 只有这个点第一次从堆中出来的时候，也就是当前点是当前堆中最小值时，它的值才一定是最优解。
        if (x == n && y == m) return dis[x][y];
        
        // st[][]和dijkstra中类似的作用
        if (st[x][y]) continue;
        st[x][y] = true;

        for (int i = 0; i < 4; ++i) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a > n || b < 0 || b > m) continue;
            // w: 从g[x][y]->g[a][b]如果需要翻转才能到达, 那么权值是1, 否则是0
            int ga = x + ix[i], gb = y + iy[i], w = g[ga][gb] != cs[i];
            if (dis[x][y] + w <= dis[a][b]) {
                dis[a][b] = dis[x][y] + w;
                if (!w) dq.push_front({a, b});
                else dq.push_back({a, b});
            }
        }
    }
    return -1; // 这里一定不会执行到
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> g[i];
        // 起点g[0][0]是偶数点, 那么横纵坐标之和为偶数的点是可达点
        if (n + m & 1) cout << "NO SOLUTION" << endl; 
        else cout << bfs() << endl;
    }

    return 0;
}