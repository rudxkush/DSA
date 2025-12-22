ListNode* Solution::solve(ListNode* A) {
    ListNode *odd = A;
    ListNode *even = NULL;
    // ListNode *p = A;
    while(odd && odd->next){
        ListNode *temp = odd->next;
        odd->next = odd->next->next;
        temp->next = even;
        even = temp;
        odd = odd->next;
    }
    odd = A;
    
    while(even){
        ListNode *temp = even->next;
        even->next = odd->next;
        odd->next = even;
        even = temp;
        odd = odd->next->next;
    }
    return A;
} 
