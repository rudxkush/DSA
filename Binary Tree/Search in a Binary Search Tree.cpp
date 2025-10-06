TreeNode* searchInBT(TreeNode* root, int target) {
  while(root != NULL && root->val != target) {
  	if(root->val < target) {
  		root = root->right;
    } else {
      root = root->left;
    }
  }	
  return root;
}
