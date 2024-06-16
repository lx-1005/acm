/** 
 *     author:  JiuR
 *     created: 2024-06-16 00.36.11
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;
#define rep(i,a,n) for(int i = a; i<n; i++)
#define per(i,a,n) for(int i = n-1; i>= a; i--)
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define bitcnt(x) __builtin_popcountll(x) // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))          // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) __builtin_ctz(x) // 返回x的二进制末尾0的数量，等价于x的最低位1是第几位
#define bitcnt_headzero(x) (__builtin_clz(x)) // 返回x的二进制开头0的数量
#define sz(x) (int)(x.size())
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

假设存在偶数方案，使得n=a1+a2+...+ak，那么将a[1~k-1]变成2，多出来的部分放到ak上，一定也是一种偶数方案
奇数方案同理，a[1~k-1]变成1，最后一个n-(k-1)也是奇数


*/

void solve() {
    int n, k;
    cin >> n >> k;

    int n1 = n-(k-1)*2;
    if (n1 > 0 && n1%2==0) {
        cout << "YES" << '\n';
        for (int i = 0; i < k - 1; i++) cout << 2 << ' ';
        cout << n-(k-1)*2 << '\n';
        return;
    } 

    int n2 = n-(k-1);
    if (n2 > 0 && n2%2) {
        cout << "YES" << '\n';
       for (int i = 0; i < k - 1; i++) cout << 1 << ' ';
        cout << n-(k-1) << '\n'; 
        return;
    }

    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    auto start_time = clock();

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    auto end_time = clock();
#ifdef LOCAL
    std::cerr << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms"
              << "\n";  // 输出运行时间
#endif

    return 0;
}