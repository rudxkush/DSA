class Solution {
public:
    int rec(TreeNode* root, int& counter, int k) {
        if(root == NULL) {
            return -1;
        }
        
        int left = rec(root->left, counter, k);
        counter++;
        if(counter == k) {
            return root->val;
        }
        int right = rec(root->right, counter, k);
        
        if(left == -1) {
            return right;
        } else {
            return left;
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        return rec(root, counter, k);
    }
};
