class Solution {
public:
    ListNode* partition(ListNode* A, int B) {
        ListNode* curr = A;
        ListNode* lessDummy = new ListNode(0);
        ListNode* greaterEqualDummy = new ListNode(0);
        ListNode* head = lessDummy;
        ListNode* tail = greaterEqualDummy;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = NULL;
            if (curr->val < B) {
                head->next = curr;
                head = curr;
            } else {
                tail->next = curr;
                tail = curr;
            }
            curr = nextNode;
        }
        head->next = greaterEqualDummy->next;
        return lessDummy->next;
    }
};
