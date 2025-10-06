void getAllLeft(stack<TreeNode*>& st, TreeNode* node) {
  while(node != NULL) {
    st.push(node);
    node = node->left;
  }
}

void iterativeInorder(TreeNode* root) {
  if(root == NULL) return;
  stack<TreeNode*> st;
  getAllLeft(st, root);

  while(!st.empty()) {
    TreeNode* curr = st.top(); 
    st.pop();

    cout << curr->val << " ";

    if(curr->right != NULL) {
      getAllLeft(st, curr->right);
    }
  }
}

void recursiveInorder(TreeNode* root) {
  if(root == NULL) {
    return ;
  }
  recursiveInorder(root->left);
  cout << root->val << " ";
  recursiveInorder(root->right);
}
