TreeNode* prev = NULL;
void recflatten(TreeNode* root) {
    if(root == NULL) return ;

    recflatten(root->right);
    recflatten(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

prev = NULL;
void iterativeflatten(TreeNode* root) {
    if(root == NULL) return ;
    st.push(root);
    while(!st.empty()) {
        TreeNode* curr = st.top(); st.pop();
        if(curr->right != NULL) st.push(curr->right);
        if(curr->left != NULL) st.push(curr->left);
        if(!st.empty()) curr->right = st.top();
        curr->left = NULL;
    }
}
