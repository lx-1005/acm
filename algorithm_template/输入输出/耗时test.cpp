
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void time() {
    milliseconds start_time = duration_cast<milliseconds >(system_clock::now().time_since_epoch());

    // 把要执行的程序放在这里
    

    milliseconds end_time = duration_cast<milliseconds >(system_clock::now().time_since_epoch());

    cout << "耗时:" << end_time.count() - start_time.count() << " ms"<< endl;
}

int main() {
    
    time();


    return 0;
}