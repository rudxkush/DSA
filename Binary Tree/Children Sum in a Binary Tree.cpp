class Solution {
  public:
    int rec(Node* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) 
            return root->data;

        int left = rec(root->left);
        if(left == -1) return -1;
        int right = rec(root->right);
        if(right == -1) return -1;
        
        if(root->data != left + right) 
            return -1;
        
        return root->data; 
    }
    int isSumProperty(Node *root) {
        return rec(root) != -1 ? 1 : 0;
    }
};
