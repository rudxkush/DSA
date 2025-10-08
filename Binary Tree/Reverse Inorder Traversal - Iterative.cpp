void iterativeReverseInorder(TreeNode* root) {
  stack<TreeNode*> st;
  TreeNode* curr = root;
  while(!st.empty() || curr != NULL) {
    if(curr != NULL) {
      st.push(curr);
      curr = curr->right;
    } else {
      curr = st.top();
      st.pop();
      cout << curr->val << " ";
      curr = curr->left;
  }
}
