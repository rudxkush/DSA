class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        queue<TreeNode*> q;
        q.push(root);
        string tree;
        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            if (curr == NULL) {
                tree += "#,";
                continue;
            }

            tree += to_string(curr->val) + ",";
            q.push(curr->left);
            q.push(curr->right);
        }
        return tree;
    }

    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;
      
        stringstream ss(data);
        string nodeVal;
        getline(ss, nodeVal, ',');
        TreeNode* root = new TreeNode(stoi(nodeVal));
      
        queue<TreeNode*> q;
        q.push(root);
      
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(ss, nodeVal, ',')) {
                if (nodeVal != "#") {
                    node->left = new TreeNode(stoi(nodeVal));
                    q.push(node->left);
                }
            }
          
            if (getline(ss, nodeVal, ',')) {
                if (nodeVal != "#") {
                    node->right = new TreeNode(stoi(nodeVal));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
