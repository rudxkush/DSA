class Solution {
public:
    void dfs(TreeNode* node, bool startLeft, int length, int& ans) {
        if (node == NULL)
            return;

        ans = max(ans, length);
        if (startLeft) {
            dfs(node->left, false, length + 1, ans);
            dfs(node->right, true, 1, ans);
        } else {
            dfs(node->right, true, length + 1, ans);
            dfs(node->left, false, 1, ans);
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, true, 0, ans); 
        dfs(root, false, 0, ans); 
        return ans;
    }
};
