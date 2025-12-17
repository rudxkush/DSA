ListNode* Solution::insertionSortList(ListNode* A) {
    if(A == NULL || A->next == NULL) return A;
    ListNode* curr = A;
    ListNode* dummy = new ListNode(INT_MIN);
    
    while(curr != NULL) {
        ListNode* nextSubNodes = curr->next;
        curr->next = NULL;
         
        ListNode* prev = dummy;
        while(prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }
        
        curr->next = prev->next;
        prev->next = curr;
        curr = nextSubNodes;
    }
    return dummy->next;
}
