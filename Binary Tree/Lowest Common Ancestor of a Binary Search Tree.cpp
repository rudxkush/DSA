class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->val < p->val && curr->val < q->val){
                curr = curr->right;
            } else if(curr->val > p->val && curr->val > q->val) {
                curr = curr->left;
            } else {
                return curr;
            }
        }
        return NULL;
    }
};
