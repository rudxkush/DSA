class Solution {
public:
    void pushLeftPath(TreeNode* node, stack<TreeNode*>& st) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    void pushRightPath(TreeNode* node, stack<TreeNode*>& st) {
        while (node) {
            st.push(node);
            node = node->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        stack<TreeNode*> leftStack, rightStack; // inorder, reverseInorder
        pushLeftPath(root, leftStack);   
        pushRightPath(root, rightStack); 

        while (!leftStack.empty() && !rightStack.empty() &&
               leftStack.top() != rightStack.top()) {

            int leftVal = leftStack.top()->val;
            int rightVal = rightStack.top()->val;
            int sum = leftVal + rightVal;

            if (sum == k)
                return true;

            if (sum < k) {
                TreeNode* node = leftStack.top()->right;
                leftStack.pop();
                pushLeftPath(node, leftStack);
            } else {
                TreeNode* node = rightStack.top()->left;
                rightStack.pop();
                pushRightPath(node, rightStack);
            }
        }

        return false;
    }
};
