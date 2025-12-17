ListNode* Solution::solve(ListNode* head) {
    ListNode* iter = head;
    int ones = 0, zeroes = 0;
    while (iter != NULL) {
        if (iter->val == 0) {
            zeroes++;
        } else {
            ones++;
        }
        iter = iter->next;
    }
    ListNode* curr = head;
    while (curr != NULL) {
        if (zeroes > 0) {
            curr->val = 0;
            zeroes--;
        }
        else {
            curr->val = 1;
        }
        curr = curr->next;
    }
    return head;
}
