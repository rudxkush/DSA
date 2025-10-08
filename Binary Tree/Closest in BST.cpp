class Solution {
  public:
    int minDiff(Node *root, int K) {
        int minimumDiff = INT_MAX;
        while (root != NULL) {
            minimumDiff = min(minimumDiff, abs(root->data - K));
            if (K < root->data)
                root = root->left;
            else if (K > root->data)
                root = root->right;
            else
                break; 
        }
        return minimumDiff;
    }
};
