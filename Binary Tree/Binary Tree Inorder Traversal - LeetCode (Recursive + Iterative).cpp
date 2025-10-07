void iterativeInorder(TreeNode* root) {
  if(root == NULL) return ;
  stack<TreeNode*> st;
  TreeNode* node = root;
  while (true) {
    if (node != NULL) {
      st.push(node);
      node = node->left;
    } else {
      if (st.empty()) break;
      node = st.top();
      st.pop();
      cout << node->val << " ";
      node = node->right;
    }
  }
  return ;
}

void recursiveInorder(TreeNode* root) {
  if(root == NULL) {
    return ;
  }
  recursiveInorder(root->left);
  cout << root->val << " ";
  recursiveInorder(root->right);
}
