#include <bits/stdc++.h>
using namespace std;

class LCA {
private:
    vector<vector<int>> pa; // pa[x][i]: 节点x的第2^i个祖先
    map<int, int> depth; // <节点，深度>

    int get_kth_ancestor(int node, int k) { // 返回node节点的第k个祖先
        // 按k的二进制表示走
        for (; k && (node != -1); k &= k - 1) {
            node = pa[node][__builtin_ctz(k)]; // node往上走lowbit(k)步
        }
        return node;
    }

public:
    // 节点编号为0~n-1，树以edges的方式给出
    LCA(int n, vector<vector<int>>& edges) {
        // 建图
        vector<vector<int>> g(n);
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);

        }

        int m = 32 - __builtin_clz(n); // n个节点排成单链时，m最多取到log2(n)，等价于n的二进制位数
        pa.resize(n, vector<int>(m, - 1));
        function<void(int, int)> dfs = [&](int x, int fa) { // x的父亲是fa
            pa[x][0] = fa; // 先求所有节点的父亲
            if (fa != -1) depth[x] = depth[fa] + 1;

            for (int y : g[x]) {
                if (y != fa) { // 遍历x的儿子y
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1); // 0是根节点

        // 先求所有节点的爷爷，再求所有节点的爷爷的爷爷，...
        for (int i = 1; i < m; ++i) {
            for (int x = 0; x < n; ++x) {
                if (int p = pa[x][i - 1]; p != -1) {
                    pa[x][i] = pa[p][i - 1];
                }
            }
        }
    }

    // 返回 p 和 q 的最近公共祖先（节点编号从 0 开始）
    int get_lca(int p, int q) {
        if (depth[p] > depth[q]) swap(p, q);

        // 使 q 和 p 在同一深度
        q = get_kth_ancestor(q, depth[q] - depth[p]);
        if (q == p) return p;

        // 往上走，尽量大步跨
        // p和q位于同一层，同时跨2^i步，如果p
        for (int i = pa[p].size() - 1; i >= 0; i--) {
            int pp = pa[p][i], pq = pa[q][i];
            // p和q一起往上跨2^i步，分别到pp和pq
            // 如果pp==pq，说明pp位于目标位置或目标位置的上方，说明步子迈大了
            // 如果不相等，说明pp和pq位于目标位置的下方，说明步子迈小了，此时p和q可以放心走到pp和pq，更靠近目标位置了
            if (pp != pq) {
                // 往上走
                p = pp;
                q = pq;
            }
        }
        return pa[p][0]; // 最终，只要p和q位于这棵树中，最终会走到最近公共祖先的儿子
    }
};