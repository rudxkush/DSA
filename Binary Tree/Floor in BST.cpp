class Solution {
  public:
    int floor(Node* root, int x) {
        // Code here
        int zameen = -1;
        while(root != NULL) {
            if(root->data <= x) {
                zameen = root->data;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return zameen;
    }
};
