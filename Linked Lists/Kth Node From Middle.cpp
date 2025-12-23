int Solution::solve(ListNode* A, int B) {
    if(A == NULL) return -1;
    ListNode* slow = A;
    ListNode* fast = A;
    int halfLen = 0;
    while(fast && fast->next) {
        halfLen++;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (B > halfLen) return -1;

    int targetIndex = halfLen - B;
    ListNode* curr = A;

    while (targetIndex--) {
        curr = curr->next;
    }

    return curr->val;
}
