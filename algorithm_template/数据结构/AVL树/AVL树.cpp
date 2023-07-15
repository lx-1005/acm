

#include <bits/stdc++.h>
using namespace std;

struct AVL {
private:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
    };

    TreeNode* leftRotate(TreeNode* root){ // 左旋
        if (!root || !root->right) return root;
        auto R = root->right;
        auto RL = root->right->left;
        root->right = RL;
        R->left = root;
        return R;
    }

    TreeNode* rightRotate(TreeNode* root){ // 右旋
        if (!root || !root->left) return root;
        auto L = root->left, LR = root->left->right;
        root->left = LR;
        L->right = root;
        return L;
    }

    int getHeight(TreeNode* root){ // 获取树高
        if (!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

public:

    AVL() {}

    // todo: insert和remove的实现
    void insert(int x) {

    };

    void remove(int x) {

    }


};