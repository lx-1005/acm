#include <bits/stdc++.h>

using namespace std;

/*
int a[2][2] = {{1, 1}
               {1, 0}};

[f[n], f[n-1]] = [f[n-1], f[n-2]] * a = ... = [f[1], f[0]] * a^(n-1) = [1, 0] * a^(n-1) = ret;

f[n] = ret[0][0];                                
*/

using ll = long long; // 防止数太大
const int mod = 1e9 + 7;

void multi(ll m1[2][2], ll m2[2][2]) { // 计算m1*m2, 结果存回m1
    ll tmp[2][2] = {{0, 0}, {0, 0}}; // 临时矩阵
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                tmp[i][j] = ((m1[i][k] * m2[k][j] % mod) + tmp[i][j]) % mod;
            }
        }
    }

    // 将结果赋回m1
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            m1[i][j] = tmp[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;

    if (!n) return 0;
    if (n == 1) return 1;

    ll ret[2][2] = {{1, 0}, {0, 1}}; // 初始位单位阵
    ll a[2][2] = {{1, 1}, {1, 0}}; // 核心，由递推式推出来的
    
    int cnt = n - 1;
    while (cnt) { // 求a^(n-1), 结果存在ret中
        if (cnt & 1) multi(ret, a);
        multi(a, a);
        cnt >>= 1;
    }      

    cout << ret[0][0] << endl; // ret[0][0]即f[n]

    return 0;
}