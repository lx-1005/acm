/*
 * 字典树Trie: 用于快速存储和查找字符串
 *
 * api:
 *      1. 插入单词word
 *      2. 查找单词word出现的次数
 *      3. 查找字符串集合中是否存在某前缀prefix
 */

#include <bits/stdc++.h>
using namespace std;

// 写法1: 适用于不知道节点总数时，每当需要时才增添一行，该行的行号为idx
// 缺点: 内存占用比写法2大
class Trie {
private:
    //trie的行数：节点总数; 列数：固定26，表示26个小写字母
    //trie[][]存的是下标
    vector<vector<int>> trie;
    int idx;//可用的最新下标, 根为下标0, 之后从1开始分配
    unordered_map<int, int> cnt;//cnt[i]表示以节点i结尾的单词个数
public:
    Trie() {
        trie.push_back(vector<int>(26));
        idx = 0;
    }
    
    void insert(string word) {//插入单词
        int p = 0;
        for (char c : word) {
            int u = c - 'a';
            if (!trie[p][u]) {//有就往下走，没有就创建一个往下走
                trie[p][u] = ++idx;
                trie.push_back(vector<int>(26));//由于采用的vector，事先不知道一共有多少个节点，因此只有当需要时才添加一个节点
            }
            p = trie[p][u];
        }
        cnt[p]++;//以节点p结尾的单词个数++
    }
    
    int search_word(string word) { //查找单词出现的次数
        int p = 0;
        for (auto c : word) {
            int u = c - 'a';
            if (!trie[p][u]) return 0;
            p = trie[p][u];
        }
        return cnt[p]; // 单词word的出现数目
    }
    
    bool search_prefix(string prefix) { // 集合中是否存在前缀prefix
        int p = 0;
        for (auto c : prefix) {
            int u = c - 'a';
            if (!trie[p][u]) return false;
            p = trie[p][u];
        }
        return true; // 存在prefix
    }
};


// 写法2: 适用于根据题目可以算出所需节点总数N
const int N =  1e5 + 10;//因为题目说所有操作输入的字符串总长度不超过 10^5,最坏情况下这些操作都是插入操作，且所有字符都需要建一个节点，需要1e5个节点，因此数组要开N这么大
//trie[N][26]存的是下标；
//trie[i]表示i节点的所有儿子，因为仅有小写字母，因此每个节点最多有26个儿子,初始为0，代表没有'a'~'z'任何一个儿子，例如trie[3][1]=2代表下标为3的节点有一个儿子'b',位于下标为2的位置
int trie[N][26];
int cnt[N];//cnt[i]表示以节点i为结尾的字符串个数
int idx;//当前最新的下标，用于存新节点,因此每个节点都拥有一个独立无二的下标

void insert(string& str) {//插入字符串str
    int p = 0;//初始从根节点开始
    for (int i = 0; str[i]; ++i) {//把str插到trie树中
        int u = str[i] - 'a';//str[i]字符所在位置
        if (!trie[p][u]) trie[p][u] = ++idx;//若没有所需字符，就创一个往下走
        p = trie[p][u];//逐层往下，直到把整个str字符串插入完毕
    }
    
    cnt[p]++;//以trie[p][u]结尾的字符串数量加1
}

int search_word(string& str) {//和插入操作类似，只不过在没找到所需字符时，说明str不存在于trie树中
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';//str[i]这个字符
        if (!trie[p][u]) return 0;//str这个字符串还没遍历结束，发现某个字符不存在，即该字符串不在该trie树中
        p = trie[p][u];
    }
    
    return cnt[p];//如果str字符串成功遍历结束，则返回以str最后一个字符结尾的出现次数
}

bool search_prefix(string& prefix) { // 集合中是否存在前缀prefix
    int p = 0;
    for (auto c : prefix) {
        int u = c - 'a';
        if (!trie[p][u]) return false;
        p = trie[p][u];
    }
    return true; // 存在prefix
}

