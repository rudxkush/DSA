class Solution {
public:
    TreeNode* recBuild(vector<int>& preorder, int start, int end) {
        if (start > end)
            return NULL;

        TreeNode* root = new TreeNode(preorder[start]);
        int counter = start;
        for (int i = start + 1; i <= end; i++) {
            if (preorder[i] < root->val) {
                counter++;
            }
        }

        root->left = recBuild(preorder, start + 1, counter);

        root->right = recBuild(preorder, counter + 1, end);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        /*
            Input: preorder = [8,5,1,7,10,12]
            Output: [8,5,10,1,7,null,12]

                          8, preorder[0]
                        /               \
            all member <  8              all members >  8
        */
        int n = preorder.size();
        TreeNode* temp = recBuild(preorder, 0, n - 1);
        return temp != NULL ? temp : NULL;
    }
};
