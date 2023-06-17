/*
 * 手写字符串哈希: O(1)判断一个字符串s内的任意两个子串是否相等, 通常很多次判断时才有必要这么做
 *
 * 使用:
 *      1. 根据s的长度范围修改N的值
 *      2. 先init(s), 若get_substr_hashcode(str1)==get_substr_hashcode(str2), 则认为str1==str2
 *
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10; // 字符串s长度最大值
const int p = 131; // 哈希权重
unsigned long long hashcode[N]; // hashcode[i]: 字符串s的前i个字符的哈希值
unsigned long long P[N]; // P[i]表示p^i

void init(string& s) { // 为s构造hashcode[]和P[]
    int n = s.size();
    P[0] = 1;
    for (int i = 1; i <= n; ++i) { //输入的字符从1开始，类似于前缀和问题，求某个区间[L, R]的哈希值时会用到L - 1这个下标，所以字符串下标从1开始会方便些。
        P[i] = P[i - 1] * p;
        hashcode[i] = hashcode[i - 1] * p + s[i - 1]; // 这里累加的是str[i]的ASCII值，因为字符串中只有大小写字母和数字，它们的ASCII均不是0
    }
}

unsigned long long get_substr_hashcode(int l, int r) { // 求s的任意子串s[l~r]的哈希值
    //类似于求区间的前缀和,相当于把[1, l-1]这一段左移r-l+1位，计算出的哈希值就跟[1, r]这一段中[1,l-1]相同了，相减得到后半段[l,r]的哈希值
    return hashcode[r + 1] - hashcode[l] * P[r - l + 1];
}