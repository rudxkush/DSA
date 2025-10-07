class Solution {
public:
    TreeNode* recBuild(vector<int>& preorder, vector<int>& inorder,
                       unordered_map<int, int>& inMap, int preStart, int preEnd,
                       int inStart, int inEnd) {
        if (preEnd < preStart || inEnd < inStart)
            return nullptr;

        TreeNode * root = new TreeNode(preorder[preStart]);

        int inMapLeftlen = inMap[preorder[preStart]] - inStart;
        int rootIndex = inMap[preorder[preStart]];

        root->left = recBuild(preorder, inorder, inMap, preStart + 1,
                         preStart + inMapLeftlen, inStart, rootIndex - 1);

        root->right = recBuild(preorder, inorder, inMap, preStart + inMapLeftlen + 1,
                          preEnd, rootIndex + 1, inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*                Approachin the approach!
                    preorder: [3,9,20,15,7] root->l->r
                    Inorder:  [9,3,15,20,7] l->root->r
                    inMap:    [0,1, 2, 3,4]
                           preorder[preStart] = node
                        /                             \
                preOrder Range                    Preorder Range
                [1, 1]                            [2, 3, 4]
                Inorder Range.                    Inorder range
                [0 0]                             [2, 3, 4]
        */
        unordered_map<int, int> inMap;
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }
        TreeNode* temp = recBuild(preorder, inorder, inMap, 0, n - 1, 0, n - 1);
        return temp != NULL ? temp : NULL;
    }
};
