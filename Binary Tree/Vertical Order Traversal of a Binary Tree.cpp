class Solution {
public:
    void inOrder(TreeNode* root, int x, int level,
                 map<int, map<int, multiset<int>>>& map) {
        if (root == NULL)
            return;
        inOrder(root->left, x - 1, level + 1, map);
        map[x][level].insert(root->val);
        inOrder(root->right, x + 1, level + 1, map);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL)
            return {};
        map<int, map<int, multiset<int>>> map;
        inOrder(root, 0, 0, map);

        vector<vector<int>> ans;
        for (auto it : map) {
            vector<int> col;
            for (auto p : it.second)
                col.insert(col.end(), p.second.begin(), p.second.end());
            ans.push_back(col);
        }
        return ans;
    }
};
