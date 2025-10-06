class Solution {
  public:
    bool isLeaf(Node* root) {
        return root->left == NULL && root->right == NULL;
    }
    void getLeftBoundary(Node *root, vector<int>& boundary) {
        if(root == NULL)
            return ;
        
        if(!isLeaf(root))
            boundary.push_back(root->data);
        if(root->left != NULL) {
            getLeftBoundary(root->left, boundary);
        } else if(root->right != NULL) {
            getLeftBoundary(root->right, boundary);
        } 
    }
    void getLeaves(Node *root, vector<int>& boundary) {
        if(root == NULL) {
            return ;
        }
        
        if(isLeaf(root)) {
            boundary.push_back(root->data);
        }
        getLeaves(root->left, boundary);
        getLeaves(root->right, boundary);
    }
    void getRightBoundary(Node *root, vector<int>& rightBoundary) {
        if(root == NULL)
            return ;
        
        if(!isLeaf(root))
            rightBoundary.push_back(root->data);
        if(root->right != NULL) {
            getRightBoundary(root->right, rightBoundary);
        } else if(root->left != NULL) {
            getRightBoundary(root->left, rightBoundary);
        } 
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> boundary;
        if(root == NULL) return boundary;
        // push root
        boundary.push_back(root->data);
        // leftBoundary starting from the left exclude leave nodes
        getLeftBoundary(root->left, boundary);
        // leaveNodes -> left subtree
        getLeaves(root->left, boundary);
        // leaveNodes -> right subtree
        getLeaves(root->right, boundary);
        // reverse rightBoundary starting from the right exclude leave nodes
        vector<int> rightBoundary;
        getRightBoundary(root->right, rightBoundary);
        reverse(rightBoundary.begin(), rightBoundary.end());
        // Append the reverse rightBoundary to the boundary
        boundary.insert(boundary.end(), rightBoundary.begin(), rightBoundary.end());
        return boundary;
    }
};
