
/* 返回值：
 *      返回从i开始填数字，且i前面填的数字的集合是mask，此时满足某个要求的数字的数目
 * 参数：
 *      i: 当前要填的位置
 *      mask: i前面填的数字的集合（根据题目的约束条件做调整，有时不需要mask这个参数）
 *      is_limit: 表示i前面填的数字是否都是对应位上的（也就是最大值），如果为true，当前位至多为s[i]，否则至多为9
 *      is_num: 前面是否填了数字，如果为true，代表当前位可以从0开始，否则当前位可以接着不填或者从1开始填
 */

int f[需要填的位置数目][mask状态的数目]; // 记忆化i和mask这两维
mst(f, -1);
function<int(int, int, bool, bool)> dfs = [&](int i, int mask, bool is_limit, bool is_num) -> int {
    if (i == s.size()) return is_num; // 若填过数字，则得到一个有效数字

    // 当is_limit=true（对应最大值）或is_num=false（对应最小值）时，这种情况只会走一次，因此不需要记忆化
    if (!is_limit && is_num && f[i][mask] != -1) return f[i][mask]; // 记忆化
    int res = 0;
    if (!is_num) res += dfs(i + 1, mask, false, false); // 接着不填
    int down = 1 - is_num, up = is_limit ? s[i] - '0' : 9;
    for (int d = down; d <= up; ++d) { // 枚举位置i要填的数字，范围取决于is_limit和is_num
        if (!(mask >> d & 1)) { // d 不在mask中
            res += dfs(i + 1, 选d之后的mask, is_limit && d == up, true);
        }
    }
    if (!is_limit && is_num) f[i][mask] = res;
    return res;
};