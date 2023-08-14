#ifdef LOCAL
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include "C:\Users\lx\Documents\SublimeText\dbg.hpp"
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <unordered_map>
#include <unordered_set>
using namespace __gnu_pbds; //required
using namespace std;

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
#define fi first
#define se second
#define yn(ans) printf("%s\n", (ans)?"Yes":"No");
#define YN(ans) printf("%s\n", (ans)?"YES":"NO");

using LL = long long;
using ULL = unsigned long long;
using VI = std::vector<int>;
using VLL = std::vector<LL>;
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

const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f; 
// const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
// const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int N = 6;
int n; // 规则个数
string from[N], to[N]; // 转换规则: from[i] -> to[i]
string a, b; // 起点, 终点


// 扩展q, 对应步数为step, 走过的状态为vis; 另外一个方向是other, other_step; 扩展规则为from->to
int update(vector<string>& q, int& step, unordered_set<string>& vis, unordered_set<string>& other, int other_step, string from[], string to[]) {
    vector<string> tmp;
    for (int i = 0; i < q.size(); ++i) {
        string cur = q[i];
        for (int i = 0; i < n; ++i) { // 枚举规则
            int n = cur.size(), m = from[i].size();
            for (int j = 0; j <= n - m; ++j) { // 枚举cur的起点
                auto str = cur.substr(j, m);
                if (str == from[i]) { // cur[j~j+m-1]可以替换为to[i]
                    auto ncur = cur.substr(0, j) + to[i] + cur.substr(j + m);
                    if (other.count(ncur)) return step + 1 + other_step;
                    if (!vis.count(ncur)) {
                        vis.insert(ncur);
                        tmp.push_back(ncur);
                    }
                }
            }
        }
    }
    step += 1;
    q = move(tmp);
    return 0;
}

int bfs() {
    vector<string> q1, q2;
    q1.push_back(a);
    q2.push_back(b);
    unordered_set<string> vis1, vis2;
    vis1.insert(a);
    vis2.insert(b);
    int steps1 = 0, steps2 = 0;
    while (q1.size() && q2.size()) {
        if (q1.size() < q2.size()) {
            int ans = update(q1, steps1, vis1, vis2, steps2, from, to);
            if (ans) return ans; // 两个方向相遇了
        } else {
            int ans = update(q2, steps2, vis2, vis1, steps1, to, from); // 这个方向的扩展规则是to->from
            if (ans) return ans; // 两个方向相遇了
        }
        if (steps1 + steps2 >= 10) break;
    }
    return 11;
}


void solve() {
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    while (cin >> from[n] >> to[n]) ++n;

    int ans = bfs();
    if (ans <= 10) cout << ans << endl;
    else cout << "NO ANSWER!" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
