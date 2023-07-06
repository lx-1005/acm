#include <bits/stdc++.h>
using namespace std;


// 朴素分隔
auto split(const string& s, char delim) {
    vector<string> ans;
    string cur;
    for (char ch : s) {
        if (ch != delim) {
            cur += ch;
        } else if (cur.size() > 0) {
            ans.push_back(move(cur));
            cur.clear(); // move将原对象的数据转移后，原对象为空
        }
    }
    if (cur.size() > 0) { // 末尾可能没有delim
        ans.push_back(move(cur));
    }
    return ans;
};


// stringstream
vector<string> split(string& str, char delim) { // 将str按delim切割为单个string, 并存在res中
    stringstream ss(str);
    string item;
    vector<string> res;

    while (getline(ss, item, delim)) {
        if (!item.empty()) res.push_back(item);
    }

    return res;
}