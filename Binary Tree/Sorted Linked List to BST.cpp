class Solution {
  public:
    TNode* buildBST(vector<int>& values, int leftIndex, int rightIndex) {
        if (leftIndex > rightIndex) return nullptr;
    
        int midIndex = (leftIndex + rightIndex + 1) / 2; // skew towards left
        TNode* node = new TNode(values[midIndex]);
    
        node->left = buildBST(values, leftIndex, midIndex - 1);
        node->right = buildBST(values, midIndex + 1, rightIndex);
    
        return node;
    }
    TNode *sortedListToBST(LNode *head) {
        vector<int> values;
        int length = 0;
        
        while (head) {
            values.push_back(head->data);
            head = head->next;
            length++;
        }
        
        int leftIndex = 0;
        int rightIndex = length - 1;
        return buildBST(values, leftIndex, rightIndex);
    }
};
