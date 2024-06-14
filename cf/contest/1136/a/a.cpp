#include <bits/stdc++.h>
#define f first
#define s second
int main(){
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i].f >> a[i].s;
    }
    int k;
    std::cin >> k;
    for(int i = n - 1; i >= 0; i--){
        if(k >= a[i].f){
            std::cout << n - i;
            return 0;
        }
    }
    std::cout << 0;
    return 0;
}
