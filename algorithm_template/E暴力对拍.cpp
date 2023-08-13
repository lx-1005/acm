#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
const ll mod = 998244353, N = 1e5 + 100;
const int g = 10, h = 5;//g^f g:alpnum f:len
ll n;
string s,s5,s6;
int s2[N];
int cnt[26][N],fir[26],lst[26],maxlen[26],nlen;
int arr[30], apt;
int a, b, c, d, e,tc;
bool sss;
bool c1(int siz)
{
    int p = 0;
    for (int i = 1; i <= h; i++)
    {
        if (s[i - 1] - 'a' == arr[p + 1])p++;
        if (p == siz)
        {
            //for (int i = 1; i <= apt; i++)cout << char('a' + arr[i])<<"*"; cout << '\n';
            return 1;
        }
    }
    return 0;
}
void op(int x)
{
    cout << char('a' + x);
    s6+= char('a' + x);
}
bool c2(int siz)
{
    for (int i = 1; i <= h+1 - siz; i++)
    {
        bool j3 = 1;
        for (int j = 1; j <= siz; j++)
        {
            if (s[i + j - 2] - 'a' != arr[j])j3 = 0;
        }
        if (j3)return 0;
    }
    return 1;
}
bool dfs()
{
    if (apt == h+1) { apt--; return 0; }
    if (apt)
    {
        if (c1(apt) && c2(apt))return 1;
    }
    for (int e = 0; e < g; e++)
    {
        arr[++apt] = e; if (dfs())return 1;
    }
    apt--; return 0;
}
void pre()
{
    //cin >> s; 
    s6 = "";
    s = ""; int sp = tc;for (int i = 1; i <= h; i++)s += char('a' + sp % 3), sp /= 3;cout << s << "?";
    n=s.length();
    for (int i = 1; i <= n; i++)s2[i] = s[i - 1] - 'a';
    for (int e = 0; e < 26; e++)
    {
        fir[e] = lst[e] = maxlen[e] = cnt[e][0] = nlen = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s2[i] == e)
            {
                cnt[e][i] = cnt[e][i - 1] + 1;
                nlen++; maxlen[e] = std::max(maxlen[e], nlen);
                if (!fir[e])fir[e] = i; lst[e] = i;
            }
            else
            {
                cnt[e][i] = cnt[e][i - 1]; nlen = 0;
            }
        }
    }
    apt = 0;  cout << "|";
    if (dfs())
    {
        s5 = ""; sss = 1;
        for (int i = 1; i <= apt; i++)s5+= char('a' + arr[i]);
        cout << s5;
    }
    else cout << "null",sss=0; cout << "|";
    apt = 0;
}
void solve()
{
    pre();
    for (int e = 0; e < 26; e++)if (fir[e]) { a = e; break; }
    if (lst[a] - fir[a] + 1 != maxlen[a])
    {
        for (int i = 0; i <= maxlen[a]; i++)op(a);
        cout << '\n'; return;
    }
    apt = 0; for (int e = a + 1; e < 26; e++)if (cnt[e][n] > cnt[e][lst[a]])arr[++apt] = e;
    if (apt >= 2)
    {
        b = arr[1]; c = arr[2];
        if (s2[lst[a] + 1] != b)
        {
            for (int i = 1; i <= maxlen[a]; i++)op(a);
            op(b); cout << '\n'; return;
        }
        int pt = lst[a] + 1; while (s2[pt + 1] == b && pt < n)pt++;
        if (cnt[b][pt] != cnt[b][n])
        {
            for (int i = 1; i <= maxlen[a]; i++)op(a);
            for (int i = lst[a]; i <= pt; i++)op(b);
            cout << '\n'; return;
        }
        else
        {
            for (int i = 1; i <= maxlen[a]; i++)op(a);
            for (int i = lst[a]+1; i < pt; i++)op(b);
            op(c); cout << '\n'; return;
        }
    }
    else if (apt == 0)
    {
        apt = 0; for (int e = a + 1; e < 26; e++)if (cnt[e][fir[a]-1] > cnt[e][0])arr[++apt] = e;
        if (apt<2) { cout << "-1\n"; return; }
        b = arr[1]; c = arr[2];
        if (s2[fir[a] - 1] != b) { op(b); op(a); cout << '\n'; return; }
        int pt = fir[a] - 1; while (s2[pt - 1] == b && pt >1)pt--;
        if (cnt[b][pt] == 1) { op(c); op(a); cout << '\n'; return; }
        else
        {
            int la = fir[a]+1 - pt,lb=maxlen[b]+1;
            //cout << la << "*" << lb << "&\n";
            if(lb<=la)
            {
                for (int i = 1; i <= lb; i++)op(b);
                cout << '\n'; return;
            }
            else
            {
                for (int i = 1; i <= la; i++)op(b);
                op(a); cout << '\n'; return;
            }
            
        }
    }
    else//apt==1
    {
        b = arr[1];/// cout << "A\n";
        apt = 0; for (int e = a + 1; e < 26; e++)if (cnt[e][fir[a] - 1] > cnt[e][0])arr[++apt] = e;
        if (apt == 0) { cout << "-1\n"; return; }c = arr[1];//cab
        //cout << c << "*" << b << '\n';
        if (s2[fir[a] - 1] != c) { op(c); op(a); cout << '\n'; return; }
        if(maxlen[a]>1) 
        { 
            op(c);
            for (int i = 1; i < maxlen[a]; i++)op(a);
            op(b); cout << '\n'; return;
        }
        //cout << "B\n";
        //cout << c << "*" << b << '\n';
        if (c > b) { op(c); op(b); cout << '\n'; return; }
        if (c == b)
        { 
            int pt = fir[a] - 1; while (s2[pt - 1] == c && pt > 1)pt--;
            int la = fir[a] + 1 - pt, lb = maxlen[c] + 1;
            //cout << la << "*" << lb << "&\n";
            if (lb <= la||la> cnt[c][fir[a] - 1])
            {
                for (int i = 1; i <= lb; i++)op(c);
                cout << '\n'; return;
            }
            else
            {
                for (int i = 1; i <= la; i++)op(c);
                op(a); cout << '\n'; return;
            }
        }
        if (maxlen[c] == cnt[c][n]) { for (int i = 1; i <= maxlen[c]; i++)op(c); op(b); cout << '\n'; return; }
        int pt = fir[a] - 1; while (s2[pt - 1] == c && pt > 1)pt--;
        int la = fir[a] + 1 - pt, lb = maxlen[c] + 1;
        //cout << la << "*" << lb << "&\n";
        if (lb <= la)
        {
            for (int i = 1; i <= lb; i++)op(c);
            cout << '\n'; return;
        }
        else
        {
            for (int i = 1; i <= la; i++)op(c);
            op(a); cout << '\n'; return;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(); std::cout.tie(0);
    int t = 1;
    for (int i = 1; i <= h; i++)t *= g;
    cout << "t=" << t << '\n';
    //std::cin >> t;
    while (t--)
    {
        solve(), tc++;
        if(sss&&strcmp(s5.c_str(), s6.c_str()))
        {
            cout << s5 << "*" << s6 << '\n';
            cout << "!"<<tc;break;
        }
    }
    return 0;
}