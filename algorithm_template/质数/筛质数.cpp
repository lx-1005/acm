/*
 * 质数筛： 筛选出[1~n]的所有质数
 *
 * 使用：根据题意，调节n的值
 */

#include <bits/stdc++.h>
using namespace std;

// 艾氏筛法:O(nloglogn)略大于O(n)
int n;
vector<int> primers;
vector<bool> st(n + 1);
void filter() {
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            primers.push_back(i);
            //无需挨着删除i的倍数，只需删除质数的倍数
            //因为合数的倍数一定在这之前被该合数的质因数的倍数删过了：6的2倍12，已经被2的6倍删过以及3的4倍删过了
            for (int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
}


// 线性筛: O(n)
int n;
vector<int> primers;
vector<bool> st(n + 1);
void filter() {
    //总的来说，外层i控制倍数，内层保证primers[j]*i只会被其最小质因子primers[j]删除
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) primers.push_back(i);
        
        //对于1~n的任意合数x一定会被筛掉：因为合数x一定有唯一最小质因子pj，那么当i==x/pj时，就会在st[primers[j]*i]=st[pj* x/pj]=st[x]处被筛掉，且每个合数只会有唯一的最小质因子，因此只会被筛一次
        //②当i是合数时，当j枚举到i的最小质因子时，就会i%primers[j]==0退出循环；当i是质数时，当j枚举到j==i时也会由于i%primers[j]==0退出循环
        for (int j = 0; primers[j] <= n / i; ++j) {//从小到大枚举primers[]中存入的质数；这里的primers[j]<=n条件，保证下标primers[j]*i不越界
            /*
            1.i%pj == 0, pj定为i最小质因子，pj也定为pj*i最小质因子
            2.i%pj != 0, pj定小于i的所有质因子，所以pj也为pj*i最小质因子
            因此，j从0遍历到i%primers[j]==0退出循环时，primers[j]一定是primers[j]*i的最小质因子，反过来primers[j]*i只会被其最小质因子primers[j]删掉。并且随着不断++i，就会逐渐把最小质因子primers[j]的2倍，3倍...删掉，且只删一次
            */
            st[primers[j] * i] = true;//无论什么情况，primers[j]*i一定只会被它的最小质因子删掉；例如合数12只会当i==6时，被其最小质因子2删掉
            if (i % primers[j] == 0) break;//因为从小到大枚举质数，因此第一次被i整除时，primers[j]一定是i的最小质因子
        }
    }
}