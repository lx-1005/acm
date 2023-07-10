/*
 * 字典树Trie: 用于快速存储和查找字符串
 *
 * api:
 *      1. 插入单词word
 *      2. 查找单词word出现的次数
 *      3. 查找前缀prefix出现的次数
 */

#include <bits/stdc++.h>
using namespace std;


// 动态开数组写法（开在堆上）
class Trie {
private:
    Trie* children[26]; // 下标隐式对应了保存的字符，该写法是字符串中只有大写/小写字母的情况
    int cnt; // 以该字母结尾的单词次数
public:
    Trie() { // 初始化为NULL
        memset(children, 0, sizeof children);
        cnt= 0;
    }

    ~Trie() {
        for (auto p : children) delete(p);
    }
    void insert(string& word) {
        Trie* node = this;
        for (auto c : word) {
            if (node->children[c - 'a'] == NULL) node->children[c - 'a'] = new Trie();
            node = node->children[c - 'a'];
        }
        node->cnt += 1; //标记末尾
    }

    int search(string& word) {
        Trie* node = this;
        for (auto c : word) {
            if (node->children[c - 'a'] == NULL) return 0;
            node = node->children[c - 'a'];
        }
        return node->cnt;
    }

    int startsWith(string& prefix) {
        Trie* node = this;
        for (auto c : prefix) {
            if (node->children[c - 'a'] == NULL) return 0;
            node = node->children[c - 'a'];
        }
        return node->cnt;
    }
};

// vector<vector<int>>写法（开在堆上）
class Trie {
private:
    vector<vector<int>> trie; // <节点总数，列数>，trie[][]存的是下标
    int idx; // 可用的最新下标, 根为下标0, 之后从1开始分配
    unordered_map<int, int> cnt; // cnt[i]表示以节点i结尾的单词个数
public:
    Trie() {
        trie.push_back(vector<int>(26));
        idx = 1;
    }

    void insert(string& word) {// 向集合中插入单词
        int p = 0;
        for (char c : word) {
            int u = c - 'a';
            if (!trie[p][u]) { //有就往下走，没有就创建一个往下走
                trie[p][u] = idx++;
                trie.push_back(vector<int>(26)); //由于采用的vector，事先不知道一共有多少个节点，因此只有当需要时才添加一个节点
            }
            p = trie[p][u];
        }
        cnt[p]++; // 以节点p结尾的单词个数+1
    }

    int search_word(string& word) { // 查找集合中单词出现的次数
        int p = 0;
        for (auto c : word) {
            int u = c - 'a';
            if (!trie[p][u]) return 0;
            p = trie[p][u];
        }
        return cnt[p];
    }

    bool search_prefix(string prefix) { // 集合中是否存在前缀prefix
        int p = 0;
        for (auto c : prefix) {
            int u = c - 'a';
            if (!trie[p][u]) return false;
            p = trie[p][u];
        }
        return true;
    }
};


// 静态数组写法（开在栈上）：适用于根据题目可以算出所需节点总数N
class Trie {
    const int N =  1e5 + 10; // 根据题目范围调整
    int trie[N][26];
    int cnt[N]; // cnt[i]: 以节点i结尾的单词数目
    int idx;

    Trie() {
        memset(trie, 0, sizeof trie);
        memset(cnt, 0, sizeof cnt);
        idx = 1;
    }

    void insert(string& word) {
        int p = 0;
        for (int i = 0; i < word.size(); ++i) {
            int u = word[i] - 'a';
            if (!trie[p][u]) trie[p][u] = idx++;
            p = trie[p][u];
        }
        cnt[p]++;
    }

    int search_word(string& word) {
        int p = 0;
        for (int i = 0; i < word.size(); ++i) {
            int u = word[i] - 'a';
            if (!trie[p][u]) return 0; // str这个字符串还没遍历结束，发现某个字符不存在，即该字符串不在该trie树中
            p = trie[p][u];
        }

        return cnt[p];
    }

     int search_prefix(string& prefix) { // 集合中是否存在前缀prefix
        int p = 0;
        for (auto c : prefix) {
            int u = c - 'a';
            if (!trie[p][u]) return 0;
            p = trie[p][u];
        }
        return cnt[p];
    }
};

/