class Solution {
  public:
    int rec(Node* root, int& counter, int k) {
        if(root == NULL) {
            return -1;
        }
        
        int right = rec(root->right, counter, k);
        counter++;
        if(counter == k) {
            return root->data;
        }
        int left = rec(root->left, counter, k);
        
        if(left == -1) {
            return right;
        } else {
            return left; 
        }
    }
    int kthLargest(Node* root, int k) {
        int counter = 0;
        return rec(root, counter, k);
    }
};
