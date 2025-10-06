class Solution {
  public:
    int minValue(Node* root) {      // Assuming that all nodes in the BST have positive values
        if(root == NULL) return -1; // fallback value
        Node* curr = root;
        while(curr->left != NULL) {
          curr = curr->left;
        }
        return curr->data;
    }
};
