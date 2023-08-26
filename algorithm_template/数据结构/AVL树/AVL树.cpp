

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
        auto R = root->right, RL = root->right->left;
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
    TreeNode* insert(TreeNode* root, int x) {
        if (!root) return new TreeNode(x);
        if (x < root->val) root->left = insert(root->left, x);
        else root->right = insert(root->right, x);

        int balance = getHeight(root->left) - getHeight(root->right);
        if (balance > 1) {
            if (getHeight(root->left->left) < getHeight(root->left->right)) root->left = leftRotate(root->left);
            root = rightRotate(root);
        } else if (balance < -1) {
            if (getHeight(root->right->right) < getHeight(root->right->left)) root->right = rightRotate(root->right);
            root = leftRotate(root);
        }

        return root;
    }


    TreeNode* remove(TreeNode* root, int x) {
        if (!root) return root;
        if (x < root->val) root->left = remove(root->left, x);
        else if (x > root->val) root->right = remove(root->right, x);
        else {
            if (!root->left || !root->right) {
                auto temp = root->left ? root->left : root->right;
                delete root;
                root = temp;
            } else {
                auto temp = root->right;
                while (temp->left) temp = temp->left;
                root->val = temp->val;
                root->right = remove(root->right, temp->val);
            }
        }

        if (!root) return root;

        int balance = getHeight(root->left) - getHeight(root->right);
        if (balance > 1) {
            if (getHeight(root->left->left) >= getHeight(root->left->right)) {
                root = rightRotate(root);
            } else {
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        } else if (balance < -1) {
            if (getHeight(root->right->right) >= getHeight(root->right->left)) {
                root = leftRotate(root);
            } else {
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }

        return root;
    }
};


//class AVL
//{
//public:
//    map<TreeNode*, int> heightMap;
//    TreeNode* rotateLeft(TreeNode* &root) //RR
//    {
//        TreeNode* newRoot = root->right;
//        root->right = newRoot->left;
//        newRoot->left = root;
//        heightMap[root] = max(getHeight(root->left), getHeight(root->right)) + 1;
//        heightMap[newRoot] = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
//        return newRoot;
//    }
//
//    TreeNode* rotateRight(TreeNode* &root) //LL
//    {
//        TreeNode* newRoot = root->left;
//        root->left = newRoot->right;
//        newRoot->right = root;
//        heightMap[root] = max(getHeight(root->left), getHeight(root->right)) + 1;
//        heightMap[newRoot] = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
//        return newRoot;
//    }
//
//    TreeNode* rotateLeftRight(TreeNode* &root) //LR
//    {
//        root->left = rotateLeft(root->left);
//        return rotateRight(root);
//    }
//
//    TreeNode* rotateRightLeft(TreeNode* &root) //RL
//    {
//        root->right = rotateRight(root->right);
//        return rotateLeft(root);
//    }
//
//    TreeNode* insert(TreeNode* &root, int value)
//    {
//        if (!root)
//        {
//            root = new TreeNode(value);
//            heightMap[root] = 1;
//            return root;
//        }
//        if (root->val == value)
//            return root;
//        if (root->val > value)
//        {
//            insert(root->left, value);
//            if (getHeight(root->left) - getHeight(root->right) > 1)
//            {
//                if (root->left->val > value)
//                    root = rotateRight(root);
//                else if (root->left->val < value)
//                    root = rotateLeftRight(root);
//            }
//        }
//        else
//        {
//            insert(root->right, value);
//            if (getHeight(root->left) - getHeight(root->right) < -1)
//            {
//                if (root->right->val < value)
//                    root = rotateLeft(root);
//                else if (root->right->val > value)
//                    root = rotateRightLeft(root);
//            }
//        }
//        heightMap[root] = max(getHeight(root->left), getHeight(root->right)) + 1;
//        return root;
//    }
//
//    int getHeight(TreeNode* root)
//    {
//        if (!root)
//            return 0;
//        return heightMap[root];
//    }
//};