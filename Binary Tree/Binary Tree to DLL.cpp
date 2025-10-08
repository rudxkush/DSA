class Solution {
  public:
    Node* bToDLL(Node* root) {
        // left -> prev
        // right -> next
        stack<Node*> st;
        Node* curr = root;
        Node* head = NULL;
        Node* prev = NULL;
        
        while(!st.empty() || curr != nullptr) {
            while(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            
            if(head == NULL) {
                head = curr; 
            }
            if(prev != NULL) {
                prev->right = curr;
                curr->left = prev;
            } 
            prev = curr;
            curr = curr->right;
        }
        return head;
    }
};
