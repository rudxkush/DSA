class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceiling = -1;
        while(root != NULL) {
            if(root->data >= x) {
                ceiling = root->data;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ceiling;
    }
};
