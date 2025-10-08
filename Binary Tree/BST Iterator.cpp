class BSTIterator {
    vector<int> inorder;
    int currIdx;

    void rec(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) return;
        rec(root->left, inorder);
        inorder.push_back(root->val);
        rec(root->right, inorder);
    }

public:
    BSTIterator(TreeNode* root) {
        rec(root, inorder);
        currIdx = 0;
    }

    int next() {
        return inorder[currIdx++];
    }

    bool hasNext() {
        return currIdx < inorder.size();
    }
};
