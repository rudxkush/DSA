void insertNode(TreeNode* root, int num) {
    if (root == NULL)
        return new TreeNode(num);
    TreeNode* curr = root;
    while (true) {
        if (curr->val <= num) {  // is on the right part of this node
            if (curr->right != NULL) {
                curr = curr->right;
            } else {
                curr->right = new TreeNode(num);
                break;
            }
        } else {                // is on left part of this node
            if (curr->left != NULL) {
                curr = curr->left;
            } else {
                curr->left = new TreeNode(num);
                break;
            }
        }
    }
    return root;
}
