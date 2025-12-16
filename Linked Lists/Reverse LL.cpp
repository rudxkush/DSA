ListNode* Solution::reverseList(ListNode* A) {
    ListNode* prev = nullptr;
    ListNode* current = A;

    while (current) {
        ListNode* next_node = current->next;  // Store the next node
        current->next = prev;                 // Reverse the current node's pointer
        prev = current;                       // Move 'prev' to the current node
        current = next_node;                  // Move 'current' to the next node
    }

    return prev; 
};
