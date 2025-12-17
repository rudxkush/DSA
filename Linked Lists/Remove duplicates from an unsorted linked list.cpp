class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        unordered_map<int, int> seen;
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        while(head != NULL) {
            if(seen.count(head->data) > 0) {
                // Do Nothing
            } else {
                curr->next = head;
                curr = curr->next;
                seen[head->data]++;
            }
            head = head->next;
        }
        curr->next = NULL;
        return dummy->next;
    }
};
