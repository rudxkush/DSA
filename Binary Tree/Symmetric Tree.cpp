class Solution {
public:
    bool isMirror(TreeNode* r1, TreeNode* r2) {
        if (r1 == NULL && r2 == NULL) return true;
        if (r1 == NULL || r2 == NULL) return false;

        return (r1->val == r2->val)
            && isMirror(r1->left, r2->right)
            && isMirror(r1->right, r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true; // empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};
