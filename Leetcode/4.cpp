#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;

#define PB push_back
#define EB emplace_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define MT make_tuple
#define rep(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define REP(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define per(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define bitcnt(x) __builtin_popcountll(x) // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))   // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) (__builtin_ctz(x))   // 返回x的二进制末尾0的数量，例如16(10000)末尾有4个0
#define SZ(x) (int)(x.size())
#define shuffle(a) random_shuffle(all(a)) // 随机打乱a
#define endl '\n'
#define fi first
#define se second
#define yn(ans) printf("%s\n", (ans)?"Yes":"No");
#define YN(ans) printf("%s\n", (ans)?"YES":"NO");

using LL = long long;
using ULL = unsigned long long;
using DB = double;
using VLL = std::vector<LL>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;
using VB = std::vector<bool>;
using VVB = std::vector<std::vector<bool>>;
using PII = std::pair<int, int>;
using PLL = std::pair<LL, LL>;
using PCI = pair<char, int>;
using TIII = std::tuple<int, int, int>;

// 支持下标访问的ordered_set/ordered_multiset
// 使用:
//      ordered_set<int> s; 或 ordered_multiset<int> s;
//      s.find_by_order(下标); // 返回s[下标]的迭代器
//      s.order_of_key(x); // 返回s中严格<x的元素个数
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> T MOD(T a, T m) { return (a % m + m) % m; } // 求 a%m
template<typename T> T gcd(T a, T b) { return __gcd(a, b); } // a和b的最大公约数
template<typename T> T lcm(T a, T b) { return a / __gcd(a, b) * b; } // a和b的最小公倍数
template<typename T> T quick_power(T x, T y, T mod){ T res = 1, cur = x; while (y) { if (y & 1) res = res * cur % mod; cur = cur * cur % mod; y >>= 1; }return res % mod; }

const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f; // 10亿, 20亿
const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};


vector<vector<int>> pa; // pa[x][i]: 节点x的第2^i个祖先
map<int, int> depth; // <节点，深度>

// 节点编号为0~n-1，树以edges的方式给出，求p和q的最近公共祖先
int (int n, vector<vector<int>>& edges, int p, int q) {
    vector<vector<int>> g(n);
    for (auto& edge : edges) {
        int x = edge[0], y = edge[1];
        g[x].push_back(y);
        g[y].push_back(x);

    }

    int m = log(n) / log(2) + 1;
    pa.resize(n, vector<int>(m, - 1));
    function<void(int, int)> dfs = [&](int x, int fa) { // x的父亲是fa
        pa[x][0] = fa;
        if (fa != -1) depth[x] = depth[fa] + 1;

        for (int y : g[x]) {
            if (y != fa) { // 遍历x的儿子y
                dfs(y, x);
            }
        }
    };
    dfs(0, -1); // 0是根节点

    for (int i = 1; i < m; ++i) {
        for (int x = 0; x < n; ++x) {
            if (int p = pa[x][i - 1]; p != -1) {
                pa[x][i] = pa[p][i - 1];
            }
        }
    }

    int dp = depth[p], dq = depth[q];
    if (dp < dq) dq = pa[q][]

    for (int i = m; i >= 0; --i) {

    }


}

int get_kth_ancestor(int node, int k) { // 返回node节点的第k个祖先
    for (; k && (node != -1); k &= k - 1) {
        node = pa[node][lowbit(k)];
    }
    return node;
}

// 返回 x 和 y 的最近公共祖先（节点编号从 0 开始）
int get_lca(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);

    // 使 y 和 x 在同一深度
    y = get_kth_ancestor(y, depth[y] - depth[x]);
    if (y == x) return x;

    // 尽量大步跨
    // [
    for (int i = pa[x].size() - 1; i >= 0; i--) {
        int px = pa[x][i], py = pa[y][i];
        if (px != py) {
            x = px;
            y = py;
        }
    }
    return pa[x][0];
}




void solve() {
    int x;
    cin >> x;
    cout << log(x) / log(2) << endl;


}


#define INPUT_FILE "F:/coder/acm/input.txt"
#define OUTPUT_FILE "F:/coder/acm/output.txt"
#define ERROR_FILE "F:/coder/acm/error.txt"

int main() {
#ifdef LOCAL
    freopen(INPUT_FILE, "r", stdin); freopen(OUTPUT_FILE, "w", stdout); freopen(ERROR_FILE, "w", stderr);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}