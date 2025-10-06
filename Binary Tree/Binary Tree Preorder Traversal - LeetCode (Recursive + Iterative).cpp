void iterativePreorder(TreeNode* root) {
  if(root == NULL) return ;  
  stack<TreeNode*> st;
  st.push(root);
  
  while(!st.empty()) {
    TreeNode* curr = st.top(); st.pop();
    cout << curr->val << " ";

    if(curr->right != NULL) st.push(curr->right);
    if(curr->left != NULL) st.push(curr->left);
  }
  return ;
}

void recursivePostorder(TreeNode* root) {
  if(root == NULL) {
    return ;
  }
  cout << root->val << " ";
  recursiveInorder(root->left);
  recursiveInorder(root->right);
}
