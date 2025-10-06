int maxElement(Node* root) { // Assuming that all nodes in the BST have positive values
  if(root == NULL) return -1; // fallback value

  Node* curr = root;
  while(curr->right != NULL) {
      curr = curr->right;
  }
  return curr->data;
}
