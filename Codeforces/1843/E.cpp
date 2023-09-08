#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define MT make_tuple
#define rep(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define REP(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define RREP(i, a, b) for(int i = (a); i >= (int)(b); --i)
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

using LL = long long;
using VLL = std::vector<LL>;
using VVLL = std::vector<VLL>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;
using VB = std::vector<bool>;
using VVB = std::vector<std::vector<bool>>;
using PII = std::pair<int, int>;
using PLL = std::pair<LL, LL>;

template<typename T> T lcm(T a, T b) { return a / __gcd(a, b) * b; } // a和b的最小公倍数
template<typename T> T quick_power(T x, T y, T mod){ T res = 1, cur = x; while (y) { if (y & 1) res = res * cur % mod; cur = cur * cur % mod; y >>= 1; }return res % mod; }
// ------------------------------------ac--------------------------------------------------------------------------------------------------------------------------------------
const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f; // 10亿, 20亿
// const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
// const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        l[i] -= 1, r[i] -= 1;
    }
    int q;
    cin >> q;
    vector<int> x(q);
    for (int i = 0; i < q; ++i) {
        cin >> x[i];
        x[i] -= 1;
    }

    // lo]: 不存在优美区间 [hi: 存在优美区间
    int lo = -1, hi = q + 1; // 二分操作次数
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        vector<int> s(n + 1); // 前缀和
        for (int i = 0; i < mid; ++i) {
            s[x[i] + 1] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            s[i] += s[i - 1];
        }
        bool ok = false;
        for (int i = 0; i < m; ++i) {
            if (s[r[i] + 1] - s[l[i]] > (r[i] - l[i] + 1) / 2) {
                ok = true;
            }
        }
        if (ok) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    int ans = hi;
    if (hi > q) {
        ans = -1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}