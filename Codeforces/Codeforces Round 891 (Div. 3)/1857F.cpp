#include <bits/stdc++.h>
<<<<<<< HEAD
using namespace std;

#define PB push_back
=======
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;

#define PB push_back
#define EB emplace_back
#define PF push_front
>>>>>>> aefcd8977029efd2afd337fff036f1b4033e91ed
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define MT make_tuple
<<<<<<< HEAD
#define rep(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define REP(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define rrep(i, a, b) for(int i = (a); i >= (int)(b); --i)
=======
#define For(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define RFOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
>>>>>>> aefcd8977029efd2afd337fff036f1b4033e91ed
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
<<<<<<< HEAD

using LL = long long;
using VLL = std::vector<LL>;
using VVLL = std::vector<VLL>;
=======
#define yn(ans) printf("%s\n", (ans)?"Yes":"No");
#define YN(ans) printf("%s\n", (ans)?"YES":"NO");

using LL = long long;
using ULL = unsigned long long;
using DB = double;
using VLL = std::vector<LL>;
>>>>>>> aefcd8977029efd2afd337fff036f1b4033e91ed
using VI = std::vector<int>;
using VVI = std::vector<VI>;
using VB = std::vector<bool>;
using VVB = std::vector<std::vector<bool>>;
using PII = std::pair<int, int>;
using PLL = std::pair<LL, LL>;
<<<<<<< HEAD

template<typename T> T lcm(T a, T b) { return a / __gcd(a, b) * b; } // a和b的最小公倍数
template<typename T> T quick_power(T x, T y, T mod){ T res = 1, cur = x; while (y) { if (y & 1) res = res * cur % mod; cur = cur * cur % mod; y >>= 1; }return res % mod; }
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f; // 10亿, 20亿
// const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
// const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

const int N = 200010;
int a[N];

LL my_sqrt(LL x) {
    LL l = 0, r = 2000000010;
    while (l + 1 < r) {
        LL mid = l + r >> 1;
        if (mid * mid >= x) r = mid;
        else l = mid;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    map<int, LL> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        LL x, y, d;
        cin >> x >> y;
        d = x * x - 4 * y;
        if (d < 0) {
            cout << 0 << ' ';
        } else if (d == 0) {
            cout << 1ll * mp[x / 2] * (mp[x / 2] - 1) / 2 << ' ';
        } else {
            LL d1 = (x - my_sqrt(d)) / 2;
            LL d2 = (x + my_sqrt(d)) / 2;
            if (d1 + d2 != x || d1 * d2 != y) cout << 0 << ' ';
            else {
                cout << 1ll * mp[d1] * mp[d2] << ' ';
            }
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
=======
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
// const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
// const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

<<<<<<<< HEAD:Codeforces/Codeforces Round 883 (Div. 3)/1846C.cpp
/*

任务解决的顺序：从短到长

*/


int solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<PLL> score(n);
    for (int i = 0; i < n; ++i) {
        vector<int> v(m);
        for (int j = 0; j < m; ++j) {
            cin >> v[j];
        }
        sort(all(v));
        LL x = 0, y = 0; // 得分，罚分
        for (int j = 0, s = 0; j < m; ++j) {
            s += v[j];
            if (s <= h) ++x, y += s;
            else break;
        }
        score[i] = {x, y};
    }
    
    auto z = score[0]; // 鲁道夫
    sort(all(score), [](const auto& s1, const auto& s2) {
        return s1.first == s2.first ? s1.second < s2.second : s1.first > s2.first;
    });

    for (int i = 0; i < n; ++i) {
        // 第一次遇到和鲁道夫相同的<得分, 罚分>, 就当做鲁道夫
        if (score[i] == z) return i + 1;
    }
    return -1;
========


void solve() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));

    cin >> q;
    for (int t = 0; t < q; ++t) {
        LL x, y;
        cin >> x >> y;

        LL ans = 0;
        for (int i = 0; i < n; ++i) {
            if (y % a[i] || y - a[i] < a[0] || y - a[i] > a[n - 1]) {
                continue;
            }
            int l = lower_bound(a.begin() + i + 1, a.end(), x - a[i]) - a.begin();
            int r = upper_bound(a.begin() + i + 1, a.end(), x - a[i]) - a.begin();
            if (l < r) {
                // [l, r)
                int ll = lower_bound(a.begin() + l, a.begin() + r, y / a[i]) - a.begin();
                int rr = upper_bound(a.begin() + l, a.begin() + r, y / a[i]) - a.begin();
                if (ll < rr) ans += rr - ll;
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
>>>>>>>> aefcd8977029efd2afd337fff036f1b4033e91ed:Codeforces/Codeforces Round 891 (Div. 3)/1857F.cpp
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) cout << solve() << endl;
>>>>>>> aefcd8977029efd2afd337fff036f1b4033e91ed

    return 0;
}
