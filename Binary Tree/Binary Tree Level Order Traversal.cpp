class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                level.push_back(current->val);

                if (current->left != nullptr)
                    q.push(current->left);

                if (current->right != nullptr)
                    q.push(current->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
