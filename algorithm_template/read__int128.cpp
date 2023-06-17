#include <bits/stdc++.h>

using namespace std;

inline __int128 read() {//__int128不支持cin, cout, 因此需要手写read, print
    __int128 x = 0, f = 1;//x存数值，f存正负
    char ch = getchar();
    while (ch < '0'|| ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x *= -1;
    }
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main(void){
    __int128 a = read();
    print(a);

    return 0;
}