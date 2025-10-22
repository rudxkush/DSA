class Solution {
public:
    vector<int> ans;
    void rec(TreeNode* root) {
        if (root == NULL) 
            return;
        
        rec(root->left);
        ans.push_back(root->val);
        rec(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        rec(root);
        return ans;
    }
};
