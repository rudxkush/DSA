// brute 
class Solution {
public:
    int getHeight(TreeNode* root) {
        if(root == NULL) return 0;

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = getHeight(root->left);
        int right = getHeight(root->right);

        if(abs(left - right) > 1) return false;

        bool checkLeft = isBalanced(root->left);
        bool checkRight = isBalanced(root->right);

        return checkLeft && checkRight;
    }
};
// optimal
class Solution {
public:
    int check(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = check(root->left);
        if (left == -1) return -1;

        int right = check(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        int res = check(root);
        return res == -1 ? false : true;
    }
};
