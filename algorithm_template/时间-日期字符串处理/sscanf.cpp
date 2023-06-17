

/*
 * 功能: 将给定字符串处理成某种格式, 常用于处理日期, 时间等
 *
 * 函数原型:
 *      int sscanf(const char* s, const cahr* format, ...);
 *
 * 参数:
 *      s: C风格的字符串(对于string, 可以用c_str()转换成C风格字符串)
 *      format: 将s按照什么样的格式处理
 *
 *  返回值:
 *      如果处理成功, 返回转换成功的项数
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int y, m, d;
    char s[] = "hello 2023/1/15", k[20];
    int num = sscanf(s, "%s %d/%d/%d", k, &y, &m, &d);
    
    printf("成功填充的项数:  %d\n", num); // 4
    printf("%s %d/%d/%d", k, y, m, d); // hello 2023/1/15
    
    return 0;
}
