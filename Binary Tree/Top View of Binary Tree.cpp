class Solution {
  public:
    vector<int> topView(Node *root) {
        unordered_map<int, int> lineFirst; // {line, first_Set_Ele}
        // level order traversal
        queue<pair<Node*, int>> q;
        int minLine = 0, maxLine = 0;
        q.push({root, 0});
        while(!q.empty()) {
            auto[node, col] = q.front(); q.pop();
            
            minLine = min(minLine, col);
            maxLine = max(maxLine, col);
            
            if(!lineFirst.count(col)) {
                lineFirst[col] = node->data;
            } 
            
            if(node->left != NULL) {
                q.push({node->left, col - 1});
            }
            
            if(node->right != NULL) {
                q.push({node->right, col + 1});
            }
        }
        vector<int> res;
        for(int i = minLine; i <= maxLine; i++) {
            res.push_back(lineFirst[i]);
        }
        return  res;
    }
};
