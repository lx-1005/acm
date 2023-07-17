
// 用于找符合某种要求的子数组长度, 且目标子数组没有交集的情况
// 虽然两层循环, 但内层循环去更新外层循环 i, 因此复杂度是O(n)

int f(vector<int>& nums) {
    int n = nums.size(), i = 0, ans = -1;
    while (i < n) { // 枚举子数组左端点i
        int i0 = i; // 记录左端点
        i += 1; // 延伸右端点
        while (i < n && 符合某种要求的子数组) ++i;
        ans = max(ans, i - i0); // 更新答案: [i0, i)
    }
    return ans;
}