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

class anotherSolution {
public:
    int minimumDiff = INT_MAX;

    int helper(Node *root, int k) {
        if (root == NULL) {
            return INT_MAX;
        }

        int closestVal = abs(k - root->data);

        int left = helper(root->left, k);
        int right = helper(root->right, k);

        minimumDiff = min({minimumDiff, closestVal, left, right});

        return closestVal; 
    }

    int minDiff(Node *root, int K) {
        helper(root, K);
        return minimumDiff;
    }
};
