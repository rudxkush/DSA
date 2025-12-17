ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    while(head != NULL) {
        if(head->val != curr->val) {
            curr->next = head;
            curr = curr->next;
        }   
        head = head->next;
    }
    curr->next = NULL;
    return dummy->next;
}
