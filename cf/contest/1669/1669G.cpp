/** 
 *     author:  JiuR
 *     created: 2024-06-16 16.39.17
**/
#include <bits/stdc++.h>
using namespace std;

template<class T1, class T2> istream &operator>>(istream &cin, pair<T1, T2> &a) { return cin>>a.first>>a.second; }
template<class T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x:a) cin>>x; return cin; }
template<class T1> istream &operator>>(istream &cin, valarray<T1> &a) { for (auto &x:a) cin>>x; return cin; }
template<class T1, class T2> ostream &operator<<(ostream &cout, const pair<T1, T2> &a) { return cout<<a.first<<' '<<a.second; }
template<class T1, class T2> ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const vector<T1> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const valarray<T1> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const vector<valarray<T1>> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<'\n'<<a[i]; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const vector<vector<T1>> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<'\n'<<a[i]; return cout; }

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
inline int combination(int n, int k) { if (n == k || k == 0) { return 1; } else { return combination(n - 1, k) + combination(n - 1, k - 1); } }
ll ceilDiv(ll n, ll m) { if (n >= 0) return (n + m - 1) / m; return n / m; }
ll floorDiv(ll n, ll m) { if (n >= 0) return n / m; return (n - m + 1) / m; }
const int inf = 0x3f3f3f3f;
// const int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
//  -----------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    for (int j = 0; j < m; j++) {
        int last = n;
        for (int i = n - 1; i >= 0; i--) {
            if (g[i][j] == 'o') last = i;
            else if (g[i][j] == '*') {
                g[i][j] = '.';
                last--;
                g[last][j] = '*';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << g[i] << '\n';
    }
    cout << '\n';
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
    std::cerr << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << "\n";  // 输出运行时间
#endif

    return 0;
}