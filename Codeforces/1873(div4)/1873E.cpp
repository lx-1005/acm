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

填满需要sum单位的水
二分：h较小时，需要<=x单位的水即可填满；h较大时，需要>x的水
那么，找lb的最大值 -> rb的最小值-1

*/


bool check(vector<int>& a, ll h, ll x) {
    ll sum = 0;
    for (ll ai : a) {
        if (h > ai) {
            sum += h - ai;
        }
    }
    return sum > x;
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // lb]: 需要<=x填满 [rb: 需要>x填满
    // 找lb的最大值 -> rb-1
    ll lb = 0, rb = 2e9 + 7;
    while (lb + 1 < rb) {
        ll mid = (lb + rb) >> 1;
        if (check(a, mid, x)) rb = mid;
        else lb = mid;
    }
    cout << lb << "\n";
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