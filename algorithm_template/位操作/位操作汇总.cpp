

// a和b的交集
a & b

// a和b的并集
a | b

// a和b的对称差(a和b独有的元素)
a ^ b

// a-b(从a中减去b也有的元素)
a & (~b)

// 判断a是b的子集
a & b == a

// 判断第k位是几
x >> k & 1

// 最低位1
x & (-x)

// 去掉最低位1
x & (x-1)


// 将第k位置0
x & (~(1<<k))

// 将第k位反转
x ^ (1<<k)

// 将第k位置1
x | (1<<k)


// n个数, 从空集枚举到全集
for (int i = 0; i < 1 << n; ++i) {
    // i代表一种选择情况
}

// 遍历集合s的所有非空子集
for (int sub = s; sub; sub=(sub-1)&s)

// 遍历集合s的所有子集(包括空集)
int sub = s;
do {
    // 处理子集sub的逻辑
    sub = (sub - 1) & s;
} while (sub != s);

// Gosper's Hack: 从n个位置选择k个位置, 并以二进制的方式返回选择方案
vector<int> GospersHack(int k, int n) { //
    vector<int> masks;
    int cur = (1 << k) - 1;
    int limit = (1 << n);
    while (cur < limit) { // O(1)找出下一个方案
        masks.push_back(cur);
        int lb = cur & -cur;
        int r = cur + lb;
        cur = ((r ^ cur) >> __builtin_ctz(lb) + 2) | r;
    }
    return masks;
}



// 二进制开头0的数目
__builtin_clz(x)
__builtin_clzll(x)

// x的二进制的长度
32-__builtin_clz(x)

// 二进制末尾0的数目
__builtin_ctz(x)
__builtin_ctzll(x)

// 二进制1的个数
__builtin_popcount(x)
__builtin_popcountll(x)

// 二进制1的个数的奇偶性
__builtin_parity(x)
__builtin_parityll(x)