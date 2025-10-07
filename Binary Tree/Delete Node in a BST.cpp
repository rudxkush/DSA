class Solution {
public:
    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;

        TreeNode* rightSubtreeOfTarget = root->right;
        TreeNode* leftSubtreeOfTarget = root->left;

        TreeNode* rightMostNode = getRightMost(leftSubtreeOfTarget);
        rightMostNode->right = rightSubtreeOfTarget;
        // leftSubtreeOfTarget's left is left -> no changes
        return leftSubtreeOfTarget; 
    }

    TreeNode* getRightMost(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key)
            return helper(root);

        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->val > key) {
                if (curr->left != NULL && curr->left->val == key) {
                    curr->left =
                        helper(curr->left); // curr->left -> Target Node
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right != NULL && curr->right->val == key) {
                    curr->right = helper(curr->right);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};
