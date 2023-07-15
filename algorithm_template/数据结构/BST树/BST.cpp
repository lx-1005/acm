
struct BST {
private:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
    };

public:
    TreeNode* insert(TreeNode* root, int x) { // 插入值为key的节点
        if (!root) return new TreeNode(x);

        if (root->val > x) root->left = insert(root->left, x);
        else if (root->val < x) root->right = insert(root->right, x);
        // else { ... } // 不插入重复节点
        return root;
    }

    TreeNode* remove(TreeNode* root, int x) { // 删除值为key的节点
        if (!root) return nullptr;

        if (root->val > x) { // x在root的左子树
            root->left = remove(root->left, x);
        } else if (root->val < x) { // x在root的右子树
            root->right = remove(root->right, x);
        } else {
            if (!root->right) return root->left;
            // 找到第一个大于root->val的节点mx, 把整个root->left作为mx的左子树
            TreeNode *mx = root->right;
            while (mx->left) mx = mx->left;
            mx->left = root->left;
            return root->right;
        }

        return root;
    }

};