#include <bits/stdc++.h>

using namespace std;

#pragma once  // 防止文件被重复使用
#pragma pack(4) // 设置字节对齐

struct S{
    int x;
    char c;
    int z;
    double a;
};

int main(void) { 
    cout << offsetof(S, x) << endl;
    cout << offsetof(S, c) << endl;
    cout << offsetof(S, z) << endl;
    cout << offsetof(S, a) << endl;

    return 0;
}