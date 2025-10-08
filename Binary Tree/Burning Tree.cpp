class Solution {
  public:
    Node* searchTargetNode(Node* root, int target) {
        if(root == NULL) {
            return NULL;
        }
        // As the tree contains unique values
        if(root->data == target) {
            return root;
        }
        Node* left = searchTargetNode(root->left, target);
        Node* right = searchTargetNode(root->right, target);
        
        if(left == NULL) {
            return right;
        } else {
            return left;
        } 
    }
    void mapChildren_s_Parent(Node* root,
        unordered_map<Node*, Node*>& mp) {
        if (root == NULL)
            return;

        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;

        mapChildren_s_Parent(root->left, mp);
        mapChildren_s_Parent(root->right, mp);
    }
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> mp;
        mp[root] = NULL;
        mapChildren_s_Parent(root, mp);
        
        Node* start =  NULL;
        start = searchTargetNode(root, target);
        if(start == NULL) return -1;
        
        queue<pair<Node*, int>> q;
        q.push({start, 0});
        unordered_set<Node*> visited;
        int maxi = 0;
        
        while(!q.empty()) {
            Node* node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(visited.find(node) != visited.end()) {
                continue;
            }
            visited.insert(node);
            maxi = max(maxi, steps);
            
            for(auto nei : {node->left, node->right, mp[node]}) {
                if(nei && visited.find(nei) == visited.end()) {
                    q.push({nei, steps + 1});
                }
            }
        }
        return maxi;
    }
};
