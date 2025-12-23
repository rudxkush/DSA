ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    while(l1 || l2 || carry) {
        int a = (l1 == NULL) ? 0 : l1->val;
        int b = (l2 == NULL) ? 0 : l2->val;
        int sum = a + b + carry;
        int unitVal = sum % 10;
        carry = sum/10;
        curr->next = new ListNode(unitVal);
        curr = curr->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummy->next;
}
