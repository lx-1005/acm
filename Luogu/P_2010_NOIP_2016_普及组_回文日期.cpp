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

大模拟

*/

bool ryear(int year) { // is闰年
    return year % 400 || (year % 4 == 0 && year % 100);
}

void next_day(int& year, int& month, int& day) {
    // 特殊情况：每个月的月底
    if (month == 12 && day == 31) {
        year++, month = 1, day = 1;
        return;
    }
    if (month == 2) {
        if ((ryear(year) && day == 29) 
            || (!ryear(year) && day == 28)) {
            month = 3, day = 1;
            return;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day == 30) {
            month += 1, day = 1;
            return;
        }
        
    } else {
        if (day == 31) {
            month += 1, day = 1;
            return;
        }
    }
    // 正常情况
    day += 1;
}

string change(int year, int month, int day) {
    string s(to_string(year));
    if (month < 10) s.push_back('0');
    s += to_string(month);
    if (day < 10) s.push_back('0');
    s += to_string(day);
    return s;
}

bool check(string s) {
    for (int i = 0, j = sz(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int year1 = stoi(s1.substr(0, 4));
    int month1 = stoi(s1.substr(4, 2));
    int day1 = stoi(s1.substr(6, 2));

    int year2 = stoi(s2.substr(0, 4));
    int month2 = stoi(s2.substr(4, 2));
    int day2 = stoi(s2.substr(6, 2));

    int ans = 0;
    if (s1 == s2) {
        if (check(change(year1, month1, day1))) ++ans;
    } else {
        while (!(year1 == year2 && month1 == month2 && day1 < day2)) {
            next_day(year1, month1, day1);
            if (check(change(year1, month1, day1))) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    auto start_time=clock();
#endif

    IO;
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }







#ifdef LOCAL
    auto end_time=clock();
    std::cerr<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<"\n"; // 输出运行时间
#endif

    return 0;
}