class Solution {
public:
    void mapChildren_s_Parent(TreeNode* root,
                              unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL)
            return;

        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;

        mapChildren_s_Parent(root->left, mp);
        mapChildren_s_Parent(root->right, mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        mp[root] = NULL;
        mapChildren_s_Parent(root, mp);
        vector<int> res;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        unordered_set<TreeNode*> visited;

        while (!q.empty()) {
            TreeNode* node = q.front().first; 
            int steps = q.front().second; q.pop();
            if(visited.find(node) != visited.end()) {
                continue;
            }
            visited.insert(node);
            if(steps == k) {
                res.push_back(node->val);
                continue;
            }

            for(auto nei : {node->left, node->right, mp[node]}) {
                if(nei && visited.find(nei) == visited.end()) {
                    q.push({nei, steps + 1});
                }
            }
        }
        return res;
    }
};
