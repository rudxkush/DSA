class Solution {
  public:
    vector<int> bottomView(Node *root) {
        map<int, int> bottomOnes; // col -> {row, node->data}
        queue<pair<Node*, int>> q; // node, col
        q.push({root, 0}); // root, line
        // keep updating for the line and you get the bottom ones for every depth
        
        while(!q.empty()) {
            Node* node = q.front().first;
            int line = q.front().second; q.pop();
             
            bottomOnes[line] = node->data;  
            
            if(node->left != NULL) {
                q.push({node->left, line - 1});
            }
            
            if(node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }
        vector<int> res;
        for(auto it : bottomOnes) {
            res.push_back(it.second);
        }
        return res;
    }
};
