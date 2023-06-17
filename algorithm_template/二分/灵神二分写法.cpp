


/*
 结合灵神和yxc, 最终得到一种二分写法:
1. 二分的四种情况: >, >=, <, <=均可以转换为>=的情况, 都可以统一为>=
2. 返回nums中首个>=target的位置 ; 若数组为空, 或所有数都<target, 则返回数组长度n
 */

// 返回nums中首个>=target的位置 ; 若数组为空, 或所有数都<target, 则返回数组长度n
// 左闭右开写法
int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size(); // 左开右闭[l, r)
    while (l < r) { // 区间不为空
        // 循环不变量：
        // nums[l-1] < target
        // nums[r] >= target
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) l = mid + 1; // 范围缩小到 [mid+1, r)
        else r = mid; // 范围缩小到 [l, mid)
    }
    return l; // 返回 l 或 r 均可
}


// 返回nums中首个>=target的位置 ; 若数组为空, 或所有数都<target, 则返回数组长度n
// 开区间写法
int lower_bound(vector<int> &nums, int target) {
    int l = -1, r = nums.size(); // 开区间 (l, r)
    while (l + 1 < r) { // 区间不为空
        // 循环不变量：
        // nums[l] < target
        // nums[r] >= target
        int mid = l + (r - l) / 2;
        if (nums[mid] < target)
            l = mid; // 范围缩小到 (mid, r)
        else
            r = mid; // 范围缩小到 (l, mid)
    }
    return r; // 或者 l+1
}
