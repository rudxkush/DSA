class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* iter = dummy;
        while(iter->next && iter->next->next) {
            // we can swap the two nodes provided both the
            // adjacent nodes are not NULL
            ListNode* prev = iter;
            ListNode* nextNodes = iter->next->next->next;
            ListNode* first = iter->next;
            ListNode* second = iter->next->next;
            first->next = nextNodes;
            second->next = first;
            prev->next = second;
            iter = first;
        }
        return dummy->next;
    }
};
