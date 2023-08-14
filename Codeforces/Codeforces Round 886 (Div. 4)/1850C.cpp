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
template<typename T> T MOD(T a, T m) { return (a % m + m) % m; } // 求 a%m
template<typename T> T gcd(T a, T b) { return __gcd(a, b); } // a和b的最大公约数
template<typename T> T lcm(T a, T b) { return a / __gcd(a, b) * b; } // a和b的最小公倍数
template<typename T> T quick_power(T x, T y, T mod){ T res = 1, cur = x; while (y) { if (y & 1) res = res * cur % mod; cur = cur * cur % mod; y >>= 1; }return res % mod; }

const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f; // 10亿, 20亿
// const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
// const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};


<<<<<<<< HEAD:Codeforces/Codeforces Round 886 (Div. 4)/1850C.cpp
/*

记录单词的最上面那个字母的位置[row][col]

*/


char g[8][8];

void solve() {
    int row = -1, col = -1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> g[i][j];
            if (isalpha(g[i][j]) && row == -1) row = i, col = j;
        }
    }

    for (int i = row; i < 8 && isalpha(g[i][col]); ++i) cout << g[i][col];
    cout << endl;
========

/*

将所有奇数看做一组，偶数看做一组，只能组内交换
若sort前后，所有位置的数字的奇偶性不变，说明可以通过交换得到

*/

const int N = 200010;
int n, a[N], b[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 != b[i] % 2) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
>>>>>>>> aefcd8977029efd2afd337fff036f1b4033e91ed:Codeforces/Codeforces Round 888 (Div. 3)/1851B.cpp
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
