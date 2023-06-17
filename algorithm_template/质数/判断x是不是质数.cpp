
//判断x是不是质数: O(sqrt(x))
bool isprimer(int x) {
    if (x < 2) return false;
    
    //如果x是合数，即存在一对数的乘积==x，则其中较小的那个数一定<=根号x
    //这里的判断条件：i * i <= x这么写会溢出，i <= sqrt(x)这么写每轮求根号太慢
    for (int i = 2; i <= x / i; ++i) {//试图找出较小的质因数
        if (x % i == 0) return false;
    }
    
    return true;
}