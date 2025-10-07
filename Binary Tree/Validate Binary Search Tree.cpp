class Solution {
public:
    bool rec(TreeNode* root, long low, long high) {
        if(root == NULL) {
            return true;
        }

        if(root->val <= low || root->val >= high) return false;

        return rec(root->left, low, root->val) && rec(root->right, root->val, high);

    }
    bool isValidBST(TreeNode* root) {
        return rec(root, LONG_MIN, LONG_MAX);
    }
};
