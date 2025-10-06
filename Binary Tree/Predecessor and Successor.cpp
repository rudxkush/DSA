class Solution {
  public:
    // Find the largest value smaller than or equal to the key
    Node* findPredecessor(Node* root, int key) {
        Node* res = NULL;
        Node* curr = root;
        while(curr != NULL) {
            if(curr->data >= key) {
                curr = curr->left;
            } else {
                res = curr;
                curr = curr->right;
            }
        }
        return res;
    }
    
    // Find the smallest value greater than or equal to the key
    Node* findSuccessor(Node* root, int key) {
        Node* res = NULL;
        Node* curr = root;
        while(curr != NULL) {
            if(curr->data <= key) {
                curr = curr->right;
            } else {
                res = curr;
                curr = curr->left;
            }
        }
        return res;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = findPredecessor(root, key);
        Node* suc = findSuccessor(root, key);
        return {pre, suc};
    }
};
