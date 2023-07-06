
/*
 * 下面的vector<int>可以换成任意list, pair<int, int>等
 *
 */

#include <bits/stdc++.h>
using namespace std;


size_t Gethash(const vector<int> &v){
    static size_t P=1000000007,M=173;
    int n=v.size(); size_t res=0;
    unordered_set<int> S;
    for (int i=0;i<n;++i)S.insert(v[i]);
    for (int i=0;i<S.bucket_count();++i){
        // 利用unordered_set划分的桶
        vector<int> u(S.begin(i),S.end(i)); sort(u.begin(),u.end());
        for (int j=0;j<u.size();++j)res=((long long)res*M+u[j])%P;
    }
    return ((long long)res*M+n)%P;
}