/*
 * 功能:
 *      把用到的下标放到数组idx中, 下标的取值范围特别大, 但很稀疏, 可以离散化
 */

#include <bits/stdc++.h>
using namespace std;

void f(vector<int>& idx) {
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
}

