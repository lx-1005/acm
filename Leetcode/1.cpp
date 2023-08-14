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
<<<<<<< HEAD
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size(), ans = inf;
        set<int> st; // 存前面这个数
        for (int i = x; i < n; ++i) { // 枚举后面这个数
            st.insert(nums[i - x]);
            // 从nums[0~i-x]中，找离nums[i]最近的数*it
            auto it = st.lower_bound(nums[i]);
            ans = min({ans, abs(nums[i] - *it), abs(nums[i] - (*--it))});
=======


/*
 * 线段树: 维护"符合结合律的操作", 即根据儿子节点的信息可以求出父亲的信息, 例如最值, 和, or, xor
 *
 *
 * 使用:
 *      1. 根据题目修改maxn
 *      2. 对seg.a[0~n-1]赋值
 *         build(1, 0, n-1)建树
 *      3. 根据需要修改或查询:
 *       单点修改: O(logn)
 *          modify()
 *       查询区间最大值, 最小值, 元素和: O(logn)
 *          query_mx()
 *          query_mn()
 *          query_sum()
 */

struct SegTree {
    using LL = long long;
    static constexpr int MAXN = 200010; // 根据题目调整
    int a[MAXN]; // 原数组a

    // 根节点: tr[1]
    inline int ls(int p) { return p << 1; }     // 左儿子
    inline int rs(int p) { return p << 1 | 1; } // 右儿子

    struct Node {
        int l, r; // 该节点掌管a[l~r]
        int mx, mn; // a[l, r]的元素最值
        LL sum;    // a[l, r]的元素和
    } tr[MAXN * 4];

    //  将子节点的修改, 更新到父节点上
    void push_up(int o) {
        auto& root = tr[o], &l_son = tr[ls(o)], &r_son = tr[rs(o)];
        root.mx = max(l_son.mx, r_son.mx);
        root.mn = min(l_son.mn, r_son.mn);
        tr[o].sum = l_son.sum + r_son.sum;
    }

public:
    // 建树: build(1, 0, n - 1);
    void build(int o, int l, int r) { // o: 当前节点, l和r: 节点o掌管的区间
        if (l == r) {
            tr[o] = {l, r, a[l], a[l], a[l]};
            return;
        }

        // 递归建树
        tr[o].l = l, tr[o].r = r;
        int mid = (l + r) >> 1;
        build(ls(o), l, mid);
        build(rs(o), mid + 1, r);
        // 在回溯时, 维护父节点信息
        push_up(o);
    }

    // 查询a[L~R]的最大值: query(1, L, R);
    int query_mx(int o, int L, int R) {
        if (L <= tr[o].l && R >= tr[o].r) return tr[o].mx; // [l,r]完全包含[tr[o].l, tr[o].r]

        int mid = (tr[o].l + tr[o].r) >> 1;
        int mx = INT_MIN;
        if (L <= mid) mx = max(mx, query_mx(ls(o), L, R));
        if (R > mid) mx = max(mx, query_mx(rs(o), L, R));
        return mx;
    }

    // 查询a[L~R]的最小值: query(1, L, R);
    int query_mn(int o, int L, int R) {
        if (L <= tr[o].l && R >= tr[o].r) return tr[o].mn; // [l,r]完全包含[tr[o].l, tr[o].r]

        int mid = (tr[o].l + tr[o].r) >> 1;
        int mn = INT_MAX;
        if (L <= mid) mn = min(mn, query_mn(ls(o), L, R));
        if (R > mid) mn = min(mn, query_mn(rs(o), L, R));
        return mn;
    }

    // 查询a[L~R]的元素和: query(1, L, R);
    LL query_sum(int o, int L, int R) {
        if (L <= tr[o].l && R >= tr[o].r) return tr[o].sum; // [l,r]完全包含[tr[o].l, tr[o].r]

        int mid = (tr[o].l + tr[o].r) >> 1;
        LL s = 0;
        if (L <= mid) s += query_sum(ls(o), L, R);
        if (R > mid) s += query_sum(rs(o), L, R);
        return s;
    }

    // 修改a[idx]=x: modify(1, idx, x);
    void modify(int o, int idx, int x) {
        if (tr[o].l == tr[o].r) tr[o].mx = tr[o].mn = tr[o].sum = x; // 找到 idx 了
        else {
            int mid = (tr[o].l + tr[o].r) >> 1;
            if (idx <= mid) modify(ls(o), idx, x); // idx在左儿子
            else modify(rs(o), idx, x); // idx在右儿子
            push_up(o); // 回溯时更新父节点
>>>>>>> aefcd8977029efd2afd337fff036f1b4033e91ed
        }
    }
};



void solve() {


}


#define INPUT_FILE "F:/coder/acm/input.txt"
#define OUTPUT_FILE "F:/coder/acm/output.txt"
#define ERROR_FILE "F:/coder/acm/error.txt"

int main() {
#ifdef LOCAL
    freopen(INPUT_FILE, "r", stdin); freopen(OUTPUT_FILE, "w", stdout); freopen(ERROR_FILE, "w", stderr);
#endif
//    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) solve();

    return 0;
}