class Solution {
  public:
    void rec(Node* root, vector<int>& path, vector<vector<int>>& allRootToLeafPath) {
        if(root == NULL) {
            return ;
        } 
        path.push_back(root->data);
        if(root->left == NULL && root->right == NULL) 
            allRootToLeafPath.push_back(path);
        rec(root->left, path, allRootToLeafPath);
        rec(root->right, path, allRootToLeafPath);
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<int> path;
        vector<vector<int>> allRootToLeafPath;
        rec(root, path, allRootToLeafPath);
        return allRootToLeafPath;
    }
};
