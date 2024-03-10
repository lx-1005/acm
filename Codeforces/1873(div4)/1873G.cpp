#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// namespace R = std::ranges;
// namespace V = std::ranges::views;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
using ll = long long;
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define bitcnt(x) __builtin_popcountll(x) // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))          // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) __builtin_ctz(x) // 返回x的二进制末尾0的数量，等价于x的最低位1是第几位
#define bitcnt_headzero(x) (__builtin_clz(x)) // 返回x的二进制开头0的数量
#define sz(x) (int)(x.size())
#define IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
template <typename T1, typename T2> T1 quick_mod(T1 a, T2 m) { return (T1)(a % m + m) % m; } // 求 a%m 
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     // a和b的最小公倍数
ll quick_power(ll x, ll y, ll mod) { ll res = 1, cur = x; while (y) { if (y & 1) res = res * cur % mod; cur = cur * cur % mod; y >>= 1; } return (res % mod + mod) % mod; }
inline int combination(int n, int k) { int sum = 0; if (n == k || k == 0) { return 1; } else { return combination(n - 1, k) + combination(n - 1, k - 1); } }
ll ceilDiv(ll n, ll m) { if (n >= 0) return (n + m - 1) / m; return n / m; }
ll floorDiv(ll n, ll m) { if (n >= 0) return n / m; return (n - m + 1) / m; }
const int inf = 0x3f3f3f3f;
// const int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
//  -----------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

1. AB->BC，代表B可以从后往前不断吃掉A
BA->CB，达标B可以从前往后不断吃掉A
2. 且一旦吃掉，会变成C，因此不能后悔
3. 讨论开头和末尾字符

*/

void solve() {
    string s;
    cin >> s;

    int n = sz(s), ans = 0;
    int ca = count(s.begin(), s.end(), 'A');
    if (s[0] == 'B' || s.end()[-1] == 'B') {
        // 以B开头，每个B都可以吃掉它右侧的一排A；下个B又可以吃掉右侧的A；...
        // 以B结尾同理，每个B都可以吃掉它左侧的A
        ans = ca;
    } else if (s.find("BB") != string::npos) {
        // BB拆开，分别吃掉两侧的A
        ans = ca; 
    } else {
        // 以A开头和结尾，且不存在连着的B
        // 每个B都可以选择吃掉左侧或右侧的一排A，但一定有一组A无法吃掉
        // 放弃最短的的那组A
        int mn = 1e9;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                int cnt = 0;
                while (i < n && s[i] == 'A') {
                    cnt++;
                    i++;
                }
                mn = min(mn, cnt);
            }
        }
        ans = ca - mn;
    }
    cout << ans << "\n";
}

int main() {
#ifdef LOCAL
    auto start_time=clock();
#endif

    IO;
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }







#ifdef LOCAL
    auto end_time=clock();
    std::cerr<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<"\n"; // 输出运行时间
#endif

    return 0;
}