#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;

#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define REP(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define per(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define bitcnt(x) __builtin_popcountll(x) // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))          // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) (__builtin_ctz(x))   // 返回x的二进制末尾0的数量，等价于x的最低位1是第几位
#define bitcnt_headzero(x) (__builtin_clz(x))   // 返回x的二进制开头0的数量
#define SZ(x) (int)(x.size())
#define log2(x) log(x) / log(2)

using VI = std::vector<int>;
using VVI = std::vector<VI>;
using LL = long long;
using VLL = std::vector<LL>;
using VB = std::vector<bool>;
using VVB = std::vector<std::vector<bool>>;
using PII = std::pair<int, int>;
using PLL = std::pair<LL, LL>;

// 支持下标访问的ordered_set/ordered_multiset
// 使用:
//      ordered_set<int> s; 或 ordered_multiset<int> s;
//      s.find_by_order(下标); // 返回s[下标]的迭代器
//      s.order_of_key(x); // 返回s中严格<x的元素个数
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T1, typename T2> T1 MOD(T1 a, T2 m){return (T1)(a%m+m)%m;} // 求 a%m
LL gcd(LL a,LL b){return __gcd(a,b);} // a和b的最大公约数
LL lcm(LL a,LL b){return a/__gcd(a, b)*b;} // a和b的最小公倍数
LL quick_power(LL x, LL y, LL mod){LL res=1,cur=x;while(y){if(y&1)res=res*cur%mod;cur=cur*cur%mod;y>>=1;}return (res%mod+mod)%mod;}
inline int combination(int n,int k){if(n==k||k==0){return 1;}else{return combination(n-1,k)+combination(n-1,k-1);}}
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');return;}
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------
const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f;
//const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
//const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};


/*




*/



void solve() {
    int a, b;
    cin >> a >> b;
    cout << a +b << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}