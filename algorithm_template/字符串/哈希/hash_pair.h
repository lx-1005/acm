#ifndef HASH_PAIR_H
#define HASH_PAIR_H

#include <bits/stdc++.h>
using namespace std;


// 方法1:
// 使用: unordered_set<PII, myhash> s;
struct myhash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ hash<T2>()(p.second);
    }
};


// 方法2: 用64位表示pair
哈希: h = (LL)(p.first << 32 | p.second)
恢复: p.first = h >> 32, p.seconmd = h >> 32 & UINT_MAX;

#endif


class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        if (words.size() == 1) return words[0].size();

        int n = words.size(), ans = INT_MAX;

        function<void(int, string, int)> dfs = [&](int i, string pre, int len) {
            if (i == n) {
                ans = min(ans, len);
                return;
            }

            string s = words[i];
            int sz = s.size();
            string tmp = pre;
            if (s[0] == pre[1]) {
                pre[1] = s.back();
                dfs(i + 1, pre, len + sz - 1);
            } else {
                pre[1] = s.back();
                dfs(i + 1, pre, len + sz);
            }

            pre = tmp;
            if (s[sz - 1] == pre[0]) {
                pre[0] = s[0];
                dfs(i + 1, pre, len + sz - 1);
            } else {
                pre[0] = words[i][0];
                dfs(i + 1, pre, len + sz);
            }
        };
        string s;
        s.push_back(words[0][0]);
        s.push_back(words[0].back());
        dfs(1, s, words[0].size());
        return ans;
    }
};