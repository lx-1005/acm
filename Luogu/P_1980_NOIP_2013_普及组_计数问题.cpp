#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
using ll = long long;
using i128 = __int128_t;
#define pb push_back
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define bitcnt(x) __builtin_popcountll(x) // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))          // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) __builtin_ctz(x) // 返回x的二进制末尾0的数量，等价于x的最低位1是第几位
#define bitcnt_headzero(x) (__builtin_clz(x)) // 返回x的二进制开头0的数量
#define sz(x) (int)(x.size())
#define log2(x) log(x) / log(2)
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



*/

int f[7][2000010];

void solve() {
    int cnt = 0;
    string n, x;
    cin >> n >> x;

   
    mst(f, -1);
    function<int(int, int, bool, bool)> dfs = [&](int i, int mask, bool is_limit, bool is_num) -> int {
        if (i == n.size()) return is_num; // 若填过数字，则得到一个有效数字

        // 当is_limit=true（对应最大值）或is_num=false（对应最小值）时，这种情况只会走一次，因此不需要记忆化
        if (!is_limit && is_num && f[i][mask] != -1) return f[i][mask]; // 记忆化
        int res = 0;
        if (!is_num) res += dfs(i + 1, mask, false, false); // 接着不填
        int down = 1 - is_num, up = is_limit ? s[i] - '0' : 9;
        for (int d = down; d <= up; ++d) { // 枚举位置i要填的数字，范围取决于is_limit和is_num
            if (!(mask >> d & 1)) { // d 不在mask中
                res += dfs(i + 1, 选d之后的mask, is_limit && d == up, true);
            }
        }
        if (!is_limit && is_num) f[i][mask] = res;
    return res;
}; 
}

int main() {
#ifdef LOCAL
    clock_t start_time=clock();
#endif

    IO;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }







#ifdef LOCAL
    clock_t end_time=clock();
    cerr<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;//输出运行时间
#endif

    return 0;
}