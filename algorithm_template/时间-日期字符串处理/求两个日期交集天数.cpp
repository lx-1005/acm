
/*
 * 利用sscanf求出两段日期区间的交集天数
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int months[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // i月的天数
    
    int get(string& s) { // 将日期s转换成当年的第几天
        int m, d; // m月d日
        sscanf(s.c_str(), "%d-%d", &m, &d);
        
        int res = 0;
        for(int i = 1; i < m; ++i)res += months[i];
        return res + d;
    }
    
    // 区间求交的经典问题：max(min(b,d)-max(a,c)+1,0)
    int countDaysTogether(string a1, string a2, string b1, string b2) {
        // 假设日期均处于同一年
        // 求区间[a1, a2]与[b1, b2]的交集天数
        int a = get(a1), b = get(a2), c = get(b1), d = get(b2);
        return max(min(b, d) - max(a, c) + 1, 0);
    }
};