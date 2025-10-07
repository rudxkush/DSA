class Solution {
public:
    TreeNode* recBuild(vector<int>& inorder, vector<int>& postorder,
                       unordered_map<int, int>& inMap, int postStart,
                       int postEnd, int inStart, int inEnd) {
        if (postEnd < postStart || inEnd < inStart)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inMapRightLen = inEnd - inMap[postorder[postEnd]];
        int rootIndex = inMap[postorder[postEnd]];

        root->left =
            recBuild(inorder, postorder, inMap, postStart,
                     postEnd - inMapRightLen - 1, inStart, rootIndex - 1);

        root->right =
            recBuild(inorder, postorder, inMap, postEnd - inMapRightLen,
                     postEnd - 1, rootIndex + 1, inEnd);

        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*                Approachin the approach!
                    postorder: [9,15,7,20,3] l->r->root
                    Inorder:   [9,3,15,20,7] l->root->r
                    inMap:     [0,1, 2, 3,4]
                          postorder[postStart] = node
                        /                             \
                Postorder Range                   Postorder Range
                [1, 2, 3]                         [0, 0]
                Inorder Range.                    Inorder range
                [0 0]                             [2, 3, 4]
        */
        unordered_map<int, int> inMap;
        int n = postorder.size();
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }
        TreeNode* temp =
            recBuild(inorder, postorder, inMap, 0, n - 1, 0, n - 1);
        return temp != NULL ? temp : NULL;
    }
};
