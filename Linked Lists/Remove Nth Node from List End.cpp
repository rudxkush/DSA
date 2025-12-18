ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // To handle head deletion cleanly
    ListNode* dummy = new ListNode(0);
    dummy->next = A;

    int n = 0;
    ListNode* iter = A;
    while (iter != NULL) {
        n++;
        iter = iter->next;
    }

    // go to (n - B - 1)th node
    iter = dummy;
    for (int i = 0; i < n - B; i++) {
        iter = iter->next;
    }

    iter->next = iter->next->next;
    return dummy->next;
}
