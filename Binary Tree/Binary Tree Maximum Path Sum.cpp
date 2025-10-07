class Solution {
public:
    int rec(TreeNode* root, int& res) {
        if(root == NULL)
            return 0;

        int left = rec(root->left, res);
        int right = rec(root->right, res);

        int temp = max(root->val + max(left, right), root->val);
        int ans = root->val + left + right;
        res = max({res, temp, ans});
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        rec(root, res);
        return res;
    }
};
