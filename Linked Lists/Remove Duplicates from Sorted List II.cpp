class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        curr->next = head;
        while(head != NULL) {
            bool foundReps = false;
            while(head->next != NULL && head->next->val == curr->next->val) {
                foundReps = true;
                head = head->next;
            }
            // for curr->next->val, I have duplicates
            // provided foundReps == true
            if(foundReps) {
                curr->next = head->next;
            } else {
                curr->next = head;
                curr = curr->next;
            }
            head = head->next;
        }
        curr->next = NULL;
        return dummy->next;
    }
};
