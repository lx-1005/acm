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
#define rep(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (int)(b); --i)
=======
#define For(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define RFOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
>>>>>>> aefcd8977029efd2afd337fff036f1b4033e91ed
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
<<<<<<< HEAD
#define bitcnt(x) __builtin_popcountll(x)  // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))           // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) \
  (__builtin_ctz(x))  // 返回x的二进制末尾0的数量，例如16(10000)末尾有4个0
#define SZ(x) (int)(x.size())
#define shuffle(a) random_shuffle(all(a))  // 随机打乱a
#define endl '\n'
#define fi first
#define se second

using LL = long long;
using VLL = std::vector<LL>;
using VVLL = std::vector<VLL>;
=======
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
>>>>>>> aefcd8977029efd2afd337fff036f1b4033e91ed
using VI = std::vector<int>;
using VVI = std::vector<VI>;
using VB = std::vector<bool>;
using VVB = std::vector<std::vector<bool>>;
using PII = std::pair<int, int>;
using PLL = std::pair<LL, LL>;
<<<<<<< HEAD

template <typename T>
T lcm(T a, T b) {
  return a / __gcd(a, b) * b;
}  // a和b的最小公倍数
template <typename T>
T quick_power(T x, T y, T mod) {
  T res = 1, cur = x;
  while (y) {
    if (y & 1) res = res * cur % mod;
    cur = cur * cur % mod;
    y >>= 1;
  }
  return res % mod;
}
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f;  // 10亿, 20亿
// const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
// const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0,
// -1, -1};

const int N = 200010;
PII x[N];
LL a[N];

void solve() {
  int n;
  cin >> n;
  LL s1 = 0, s2 = 0;  // 前后缀和
  for (int i = 1; i <= n; ++i) {
    cin >> x[i].first;
    x[i].second = i;
    s2 += x[i].first;
  }
  sort(x + 1, x + n + 1);
  for (int i = 1; i <= n; ++i) {
    s2 -= x[i].first;
    s1 += x[i].first;
    a[x[i].second] = 1LL * n + 1LL * x[i].first * (2 * i - n) - s1 + s2;
  }
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
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



void solve() {


}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
>>>>>>> aefcd8977029efd2afd337fff036f1b4033e91ed
}
