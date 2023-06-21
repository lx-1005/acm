#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
using std::move;

#define PB push_back
#define EB emplace_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define MT make_tuple
#define For(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define RFOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
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
template<typename T> T quick_power(T x, T y, T mod){ T res = 1, cur = x; while (y) { if (y & 1)	res = res * cur % mod; cur = cur * cur % mod; y >>= 1; }return res % mod; }

#ifdef DEBUG
#include "F:/coder/acm/dbg.hpp"
#endif
// **************************************************************
const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f; // 10亿, 20亿
const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
//const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
//const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};


// 单点修改, 查询区间最大值
static const int maxn = 500010; // 根据题目调整
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)

struct Node {
    int l, r;
    LL sum; // 区间和
    LL t_max; // [l, r]的最大连续和
    LL l_max, r_max; // [l, r]的最大前缀和, 最大后缀和
} tr[maxn * 4];

//  将子节点的修改, 更新到父节点上
void pushup(int o) {
    tr[o].sum = tr[ls(o)].sum + tr[rs(o)].sum;
    tr[o].t_max = max({tr[ls(o)].t_max, tr[rs(o)].t_max, tr[ls(o)].r_max + tr[rs(o)].l_max});
    tr[o].l_max = max({tr[ls(o)].l_max, tr[ls(o)].sum + tr[rs(o)].l_max});
    tr[o].r_max = max({tr[rs(o)].r_max, tr[rs(o)].sum + tr[ls(o)].r_max});
}

// 建树
void build(int o, int l, int r) {
    tr[o] = {l, r};
    if (l == r) return; // 叶子

    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
}

// 查询 [l, r] 的最值, 当前位于节点 o
int query(int o, int l, int r) {
    if (l <= tr[o].l && r >= tr[o].r) return tr[o].t_max; // [l,r]完全包含[tr[o].l, tr[o].r]

    int mid = (tr[o].l + tr[o].r) >> 1;
    int mx = INT_MIN;
    if (l <= mid) mx = query(ls(0), l, r);
    if (r > mid) mx = max(mx, query(rs(o), l, r));
    return mx;
}


// 将下标idx处修改为val, 当前位于节点o
void modify(int o, int idx, int val) {
    if (tr[o].l == tr[o].r) {
        tr[o] = {idx, idx, val, val, val, val};
    }
    else {
        int mid = (tr[o].l + tr[o].r) >> 1;
        if (idx <= mid) modify(ls(o), idx, val); // idx在左儿子
        else modify(rs(o), idx, val); // idx在右儿子
        pushup(o); // 记得pushup
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    build(1, 1, n);
    
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        modify(1, i, x);
    }
    
    for (int i = 0; i < m; ++i) {
        int k, x, y; cin >> k >> x >> y;
        if (x > y) swap(x, y);
        if (k == 1) {
            cout << query(1, x, y) << endl;
        } else {
            modify(1, x, y);
        }
    }
}


#define INPUT_FILE "F:/coder/acm/input.txt"
#define OUTPUT_FILE "F:/coder/acm/output.txt"
#define ERROR_FILE "F:/coder/acm/error.txt"

int main() {
#ifdef LOCAL
//    freopen(INPUT_FILE, "r", stdin); freopen(OUTPUT_FILE, "w", stdout); freopen(ERROR_FILE, "w", stderr);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}







































