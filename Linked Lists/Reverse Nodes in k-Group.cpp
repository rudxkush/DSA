class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* nextNodes = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNodes;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;
        while (true) {
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break; 
            ListNode* head = groupPrev->next;
            ListNode* nextGroupNodes = kth->next;
            kth->next = NULL;
            ListNode* reverseHead = reverseLL(head);
            groupPrev->next = reverseHead;
            head->next = nextGroupNodes;
            groupPrev = head;
        }
        return dummy->next;
    }
};
