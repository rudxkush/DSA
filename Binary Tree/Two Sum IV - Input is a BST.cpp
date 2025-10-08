class Solution {
public:
    bool inorder(TreeNode* root, int k, unordered_set<int>& st) {
        if(root == NULL) return false;

        bool left = inorder(root->left, k, st);

        if(st.count(k - root->val)) {
            return true;
        } 
        st.insert(root->val);

        bool right = inorder(root->right, k, st);

        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return inorder(root, k, st);
    }
};
