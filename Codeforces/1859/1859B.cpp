#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define MT make_tuple
#define rep(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define REP(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define RREP(i, a, b) for(int i = (a); i >= (int)(b); --i)
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

using LL = long long;
using VLL = std::vector<LL>;
using VVLL = std::vector<VLL>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;
using VB = std::vector<bool>;
using VVB = std::vector<std::vector<bool>>;
using PII = std::pair<int, int>;
using PLL = std::pair<LL, LL>;

template<typename T> T lcm(T a, T b) { return a / __gcd(a, b) * b; } // a和b的最小公倍数
template<typename T> T quick_power(T x, T y, T mod){ T res = 1, cur = x; while (y) { if (y & 1) res = res * cur % mod; cur = cur * cur % mod; y >>= 1; }return res % mod; }
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f; // 10亿, 20亿
// const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
// const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

/*

对每组排序，可能进入答案的只可能是每组的前两个数；
对于每组的第一个数，其中最小的那个x是所有数中最小的，因此x一定会进入答案 -> 那么让它污染哪个组更好呢？


考虑：
x在的组可以当做垃圾堆，将其余所有组的第一个数（即本组最小的）都丢到x所在的组，可以让这些组都变大，且x所在的组不会受影响
此时，答案是x+其余所有组的次小数，是否有更优解呢？
既然答案是x+其余所有组的次小数 -> 我们可以将x移动到次小数最小的那组v  -> 此时答案为x+除v以外的所有组的次小值



*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        vector<int> nums(m);
        for (int j = 0; j < m; ++j) {
            cin >> nums[j];
        }
        sort(all(nums));
        a.push_back({nums[0], nums[1]});
    }

    LL ans = 0, one = -1, two = -1; 
    for (int i = 0; i < n; ++i) {
        if (two == -1 || a[i][1] < a[two][1]) {
            two = i;
        }
        if (one == -1 || a[i][0] < a[one][0]) {
            one = i;
        }
        ans += a[i][1];
    }
    ans -= a[two][1];
    ans += a[one][0];

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

/*

2 5 6 7 1001 1007
 8 11
 9


*/