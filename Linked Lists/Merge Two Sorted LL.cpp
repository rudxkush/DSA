ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    ListNode* iterA = A;
    ListNode* iterB = B;
    while(iterA != NULL && iterB != NULL) {
        if(iterA->val < iterB->val) {
            curr->next = iterA;
            iterA = iterA->next;
        } else {
            curr->next = iterB;
            iterB = iterB->next;
        }
        curr = curr->next;
    }
    if(iterA != NULL) curr->next = iterA;
    else curr->next = iterB;
    return dummy->next;
}
