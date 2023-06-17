/*
 * 拓扑序列：若一个由图中所有点构成的序列A满足，对于图中的每条有向边a->b, a在A中都出现在b之前
 *
 * 原理：有向无环图称为拓扑图，有向无环图可能存在拓扑序列，无向或成环一定不存在拓扑序列
 *  1. 拓扑序列的第一个节点，一定入度为0，只有出度，否则会成环
 *  2. 有向无环图一定至少存在一个入度为0的点，那么从这个点下手，删掉这种点的所有出边,去寻找下一个入度为0的点…
 *
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;//节点数和边数
int h[N], e[N], ne[N], idx;//图的邻接表模型
int q[N], hh, tt = -1;//队列
int d[N];//d[i]表示节点i的入度

void add(int x, int y) {//添加一条有向边x->y
    e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

void toposort() {
    //先找切入点(入度为0的点)
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) q[++tt] = i;
    }
    
    while (tt >= hh) {
        int t = q[hh++];//取出队首
        for (int i = h[t]; i != -1; i = ne[i]) {//枚举节点t的出边
            //t出边能到达的节点的入度-1，相当于去掉t->j这条边
            //涵盖了tt->t有重边的情况，当tt->t有重边，桶tt后面的单链表会有两个t号节点，因此枚举tt出边的时候，会逐个删除这两条重边，最终判决条件仍是t的入度
            int j = e[i];
            d[j]--;
            if (d[j] == 0) q[++tt] = j;//一旦出现新的入度为0的点，因为不再有其它点指向它了，因此它就在拓扑序列的最前面
        }
    }
    
    // 如果成功找到一条拓扑序列，即n个节点都会入队，tt最终停在n-1处
    // 此时q[0～n-1]就是拓扑序
    if (tt == n - 1)  {
        for (int i = 0; i < n; ++i) cout << q[i] << ' ';
        cout << endl;
    }
    else cout << -1 << endl; // 否则，一定会存在找不到入度为0的节点
}

void build() {
    cin >> n>> m;
    
    memset(h, -1, sizeof h);
    
    while (m--) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        d[y]++; //更新节点y的入度
    }
}

int main() {
    build(); // 建图
    toposort(); // 找图的一个拓扑序
    
    return 0;
}