class Solution {
public:
    TreeNode* searchTargetTreeNode(TreeNode* root, int target) {
        if (root == NULL) {
            return NULL;
        }
        // As the tree contains unique values
        if (root->val == target) {
            return root;
        }
        TreeNode* left = searchTargetTreeNode(root->left, target);
        TreeNode* right = searchTargetTreeNode(root->right, target);

        if (left == NULL) {
            return right;
        } else {
            return left;
        }
    }
    void mapChildren_s_Parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL)
            return;

        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;

        mapChildren_s_Parent(root->left, mp);
        mapChildren_s_Parent(root->right, mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp;
        mp[root] = NULL;
        mapChildren_s_Parent(root, mp);

        TreeNode* target = NULL;
        target = searchTargetTreeNode(root, start);
        if (target == NULL)
            return -1;

        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        unordered_set<TreeNode*> visited;
        int maxi = 0;

        while (!q.empty()) {
            TreeNode* TreeNode = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (visited.find(TreeNode) != visited.end()) {
                continue;
            }
            visited.insert(TreeNode);
            maxi = max(maxi, steps);

            for (auto nei : {TreeNode->left, TreeNode->right, mp[TreeNode]}) {
                if (nei && visited.find(nei) == visited.end()) {
                    q.push({nei, steps + 1});
                }
            }
        }
        return maxi;
    }
};
