

/*
 * a,b,c∈[1,1e18], 因此a*b会溢出long long, 但a+b不会溢出, 因此采用类似快速幂的思想
 *
 */

// 方法1
long long mul1(long long a, long long b, long long p) {
    long long ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        b >>= 1;
        a = a * 2 % p;
    }
    return (ans + p) % p;
}


// 方法2
long long mul2(long long a, long long b, long long p) {
    return (unsigned long long)((__int128)a * b % p);
}