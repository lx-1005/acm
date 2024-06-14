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
#define For(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define RFOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define complete_unique(a) a.erase(unique(begin(a), t(a)), t(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), t(a)
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

template<typename T>
T MOD(T a, T m) { return (a % m + m) % m; } // 求 a%m
template<typename T>
T gcd(T a, T b) { return __gcd(a, b); } // a和b的最大公约数
template<typename T>
T lcm(T a, T b) { return a / __gcd(a, b) * b; } // a和b的最小公倍数
template<typename T>
T quick_power(T x, T y, T mod) {
    T res = 1, cur = x;
    while (y) {
        if (y & 1) res = res * cur % mod;
        cur = cur * cur % mod;
        y >>= 1;
    }
    return res % mod;
}

const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f; // 10亿, 20亿
// const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
// const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int c, r, sx, sy;
char g[155][155];
int dis[155][155];
int dx[8] = {-2, -2, 2, 2, -1, 1, -1, 1}, dy[8] = {-1, 1, -1, 1, -2, -2, 2, 2};

bool check(int x1, int y1, int x2, int y2, int j) {
    if (x2 < 0 || x2 >= r || y2 < 0 || y2 >= c || g[x2][y2] == '*' || dis[x2][y2] != -1) return false;
    // if ((j < 4 && g[x1 + x2 >> 1][y1] == '*') || (j >= 4 && g[x1][y1 + y2 >> 1] == '*')) return false;
    return true;
}

int bfs() {
    mst(dis, -1);
    dis[sx][sy] = 0;
    vector<PII> q = {{sx, sy}};
    while (q.size()) { 
        vector<PII> tmp;
        for (int i = 0; i < q.size(); ++i) {
            auto [x, y] = q[i];
            int step = dis[x][y];
            for (int j = 0; j < 8; ++j) {
                int nx = x + dx[j], ny = y + dy[j];
                if (check(x, y, nx, ny, j)) {
                    dis[nx][ny] = step + 1;
                    tmp.emplace_back(nx, ny);
                    if (g[nx][ny] == 'H') {
                        return dis[nx][ny];
                    }
                } 
            }
        }
        q = move(tmp);
    }
    return -1;
}


void solve() {
    cin >> c >> r;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'K') sx = i, sy = j;
        }
    }

    cout << bfs() << endl;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}