class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        map<int, int> rightSideNodes; // {row -> lastSet}
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int row = q.front().second;
            q.pop();
            rightSideNodes[row] = node->val;
            
            if(node->left != NULL) q.push({node->left, row + 1});
            if(node->right != NULL) q.push({node->right, row + 1});
        }
        vector<int> rightView;
        for(auto it : rightSideNodes) {
            rightView.push_back(it.second);
        }
        return rightView;
    }
};
