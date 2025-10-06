class Solution {
  public:
    vector<int> leftView(Node *root) {
        map<int, int> leftSideNodes; // {row -> firstSet}
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            Node* node = q.front().first;
            int row = q.front().second;
            q.pop();
            
            if(!leftSideNodes.count(row)) {
                leftSideNodes[row] = node->data;
            }
            
            if(node->left != NULL) q.push({node->left, row + 1});
            if(node->right != NULL) q.push({node->right, row + 1});
        }
        vector<int> leftView;
        for(auto it : leftSideNodes) {
            leftView.push_back(it.second);
        }
        return leftView;
    }
};
