void iterativePostorderWithTwoStacks(TreeNode* root) {
  if(root == NULL) return;
  stack<TreeNode*> st1;
  stack<TreeNode*> st2;

  st1.push(root); 
  while(!st1.empty()) {
    TreeNode* curr = st1.top(); 
    st1.pop();

    if(curr->left != NULL) {
      st1.push(curr->left);
    }

    if(curr->right != NULL) {
      st1.push(curr->right);
    }
    
    st2.push(curr);
  }
  while(!st2.empty()) {
    TreeNode* top = st2.top(); st2.pop();
    cout << top->val << " ";
  }
  return ;
}

void iterativePostorderWithOneStack(TreeNode* root) {
  if(root == NULL) return;
  stack<TreeNode*> st;
  TreeNode* curr = root;
  
  while(!st.empty() || curr != NULL) {
    if(curr != NULL) { // processing the left here <--
      st.push(curr);
      curr = curr->left;
    } else {
      TreeNode* temp = st.top()->right;
      if(temp == NULL) {  // backtracking and processing the right here <--
        temp = st.top();
        st.pop();
        cout << temp->val << " ";

        while(!st.empty() && temp == st.top()->right) {
          temp = st.top(); st.pop();
          cout << temp->val << " ";
        }
       } else {
         curr = temp;
       } 
     } 
  }
  return ;
}

void recursivePostorder(TreeNode* root) {
  if(root == NULL) {
    return ;
  }
  recursiveInorder(root->left);
  recursiveInorder(root->right);
  cout << root->val << " ";
}
