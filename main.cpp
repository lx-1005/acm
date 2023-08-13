#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include "dbg.hpp"
#endif
using namespace __gnu_pbds;  // required
using namespace std;

#define PB push_back
#define EB emplace_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define MT make_tuple
#define rep(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define per(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define bitcnt(x) __builtin_popcountll(x)  // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))           // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) \
  (__builtin_ctz(x))  // 返回x的二进制末尾0的数量，例如16(10000)末尾有4个0
#define SZ(x) (int)(x.size())
#define shuffle(a) random_shuffle(all(a))  // 随机打乱a
#define endl '\n'
#define fi first
#define se second
#define yn(ans) printf("%s\n", (ans) ? "Yes" : "No");
#define YN(ans) printf("%s\n", (ans) ? "YES" : "NO");

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
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
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

const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f;  // 10亿, 20亿
const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1},
          dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

class Solution {
 public:
  stack<int> nums;
  stack<char> op;
  void calc() {
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();
    char c = op.top(); op.pop();
    int x = 0;
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;
    nums.push(x);
  }

  int calculate(string s) { 
    unordered_map<char, int> mp;
    mp['+'] = 1, mp['-'] = 1, mp['*'] = 2, mp['/'] = 2;

    int n = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            s[n++] = s[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') op.push(s[i]);
        else if (s[i] == ')') {
            while (op.size() && op.top() != '(') {
                calc();
            }
            op.pop();
        } else if (isdigit(s[i])) {
            int x = 0;
            while (i < n && isdigit(s[i])) x = x * 10 + s[i++] - '0';
            --i;
            nums.push(x);
        } else if (s[i] == '-') { // '-'
            if (!i || s[i - 1] == '(') {
                nums.push(0);
                op.push(s[i]);
            }
        } else { // '+', '*', '/'
            while (op.size() && op.top() != '(' && mp[s[i]] >= mp[op.top()]) {
                calc();
            }
            op.push(s[i]);
        }
    }  
    while (op.size()) {
        calc();
    }                                            
    return nums.top();
  } 
};

void solve() {}

#define INPUT_FILE "F:/coder/acm/input.txt"
#define OUTPUT_FILE "F:/coder/acm/output.txt"
#define ERROR_FILE "F:/coder/acm/error.txt"

int main() {
#ifdef LOCAL
  freopen(INPUT_FILE, "r", stdin);
  freopen(OUTPUT_FILE, "w", stdout);
  freopen(ERROR_FILE, "w", stderr);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  //    cin >> t;
  while (t--) solve();

  return 0;
}