#ifdef LOCAL
#include "/Users/lixu26/work/ACM/dbg.hpp"
#endif

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define per(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define bitcnt(x) __builtin_popcountll(x) // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))          // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) (__builtin_ctz(x))   // 返回x的二进制末尾0的数量，等价于x的最低位1是第几位
#define bitcnt_headzero(x) (__builtin_clz(x))   // 返回x的二进制开头0的数量
#define sz(x) (int)(x.size())
#define log2(x) log(x) / log(2)
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using VI = std::vector<int>;
using VVI = std::vector<VI>;
using LL = long long;
using VLL = std::vector<LL>;
using VB = std::vector<bool>;
using VVB = std::vector<std::vector<bool>>;
using PII = std::pair<int, int>;
using PLL = std::pair<LL, LL>;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
template<typename T1, typename T2> T1 MOD(T1 a, T2 m){return (T1)(a%m+m)%m;} // 求 a%m
LL gcd(LL a,LL b){return b ? gcd(b, a%b) : a;} // a和b的最大公约数
LL lcm(LL a,LL b){return a/gcd(a, b)*b;} // a和b的最小公倍数
LL quick_power(LL x, LL y, LL mod){LL res=1,cur=x;while(y){if(y&1)res=res*cur%mod;cur=cur*cur%mod;y>>=1;}return (res%mod+mod)%mod;}
inline int combination(int n,int k){int sum=0;if(n==k||k==0){return 1;}else{return combination(n-1,k)+ combination(n-1,k-1);}}
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');return;}
const int inf = 0x3f3f3f3f, INF = 0x7f7f7f7f;
//const LL infll = 0x3f3f3f3f3f3f3f3f, INFLL = 0x7f7f7f7f7f7f7f7f;
//const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

只有两种情况：交换nums1[n-1]，nums2[n-1]，以及不交换
对于每种情况，遍历[0, n-2]，如果本身满足就继续走；如果交换i可以满足，就交换后走；否则代表无法满足


*/



class Solution {
public:
    const int mx = 1e9;
    int ask(VI& nums1, VI& nums2) {
        int cnt = 0, n = sz(nums1);
        for (int i = 0; i < n - 1; i++) {
            if (nums1[i] <= nums1[n - 1] && nums2[i] <= nums2[n - 1]) continue;
            else if (nums1[i] <= nums2[n - 1] && nums2[i] <= nums1[n - 1]) cnt++;
            else return mx;
        }
        return cnt;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = sz(nums1), ans = ask(nums1, nums2);
        swap(nums1[n - 1], nums2[n - 1]);
        ans = min(ans, ask(nums1, nums2) + 1);
        return ans == mx ? -1 : ans;
    }
};



void solve() {

}






















int main() {
    IO; int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}