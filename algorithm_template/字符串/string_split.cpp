#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& str, char delim) { // 将str按delim切割为单个string, 并存在res中
    stringstream ss(str);
    string item;
    vector<string> res;

    while (getline(ss, item, delim)) {
        if (!item.empty()) res.push_back(item);
    }

    return res;
}