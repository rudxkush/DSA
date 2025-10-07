class nodeValue{
public:
    int minValue;
    int maxValue;
    int maxSize;
    nodeValue(int minValue, int maxValue, int maxSize) {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSize = maxSize;
    }
};
class Solution {
  public:
    nodeValue rec(Node* root) {
        if(root == NULL)
            return nodeValue(INT_MAX, INT_MIN, 0);
            
        auto left = rec(root->left);
        auto right = rec(root->right);
        
        if(root->data > left.maxValue && root->data < right.minValue) {
            return nodeValue(min(root->data, left.minValue), 
                             max(root->data, right.maxValue),
                             1 + left.maxSize + right.maxSize);
        } 
        return nodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    int largestBst(Node *root) {
        return rec(root).maxSize;
    }
};
