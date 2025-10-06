class Solution {
public:
    int rec(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = rec(root->left);

        int right = rec(root->right);

        return 1 + max(left, right);
    }
    int maxDepth(TreeNode* root) {
        return rec(root);
    }
};
