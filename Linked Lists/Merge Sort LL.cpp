ListNode* merge(ListNode* head, ListNode* tail) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    while (head != NULL && tail != NULL) {
        if (head->val < tail->val) {
            curr->next = head;
            head = head->next;
        } else {
            curr->next = tail;
            tail = tail->next;
        }
        curr = curr->next;
    }
    if (head != NULL) curr->next = head;
    else curr->next = tail;
    return dummy->next;
}

ListNode* mergeSort(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    // find mid for both even and odd length LL
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
     // split
    ListNode* right = slow->next;
    slow->next = NULL;

    // recurse
    ListNode* left = mergeSort(head);
    right = mergeSort(right);

    // merge
    return merge(left, right);
}
ListNode* Solution::sortList(ListNode* A) {
    return mergeSort(A);
}
