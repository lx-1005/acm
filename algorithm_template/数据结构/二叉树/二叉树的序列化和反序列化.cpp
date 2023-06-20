

// leetcode官方测试例的方法

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = -1, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};


string tree2string(TreeNode* root) { // 二叉树的序列化
    if (!root) return "[]";
    
    string s("[");
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        if (!t) s += "null,";
        else {
            s += to_string(t->val) + ",";
            q.push(t->left);
            q.push(t->right);
        }
    }
    s.back() = ']';
    return s;
}

// Decodes your encoded data to tree.
TreeNode* string2tree(string s) { // 二叉树的反序列化
    if (s == "[]") return nullptr;
    
    vector<string> data;
    stringstream ss(s.substr(1, s.size() - 2) + ",");
    while (getline(ss, s, ',')) data.push_back(s);
    
    auto root = new TreeNode(stoi(data[0]));
    queue<TreeNode*> q; // 只存非空节点
    q.push(root);
    int n = data.size(), cur = 1;
    while (cur < n) {
        // t的左儿子: data[cur]
        // t的右儿子: data[cur+1]
        auto t = q.front(); q.pop();
        if (data[cur] != "null") {
            t->left = new TreeNode(stoi(data[cur]));
            q.push(t->left);
        }
        cur += 1;
        if (data[cur] != "null") {
            t->right = new TreeNode(stoi(data[cur]));
            q.push(t->right);
        }
        cur += 1;
    }
    return root;
}