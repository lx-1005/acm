#include <bits/stdc++.h>
using namespace std;


void generate_data() {
    fstream fin("input.txt"), fout("out.txt");
    
    
    
    
    
    
}

































int main() {
    for (int i = 0; i < 10000; ++i) {
        printf("第%d轮: ");
        generate_data();
        
        system("g++ a.cpp -o a.exe <input.txt >a_output.txt");
        system("g++ b.cpp -o b.exe <input.txt >b_output.txt");
        if(system("fc a_output.txt b_out_put.txt")) { // 正确:0, 错误:1
            puts("出错了\n");
            break;
        }
    }
    
    return 0;
}







