class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        stack<ListNode*> revOrderedLL;
        ListNode* curr = slow->next;
        slow->next = NULL;
        while(curr) {
            revOrderedLL.push(curr);
            curr = curr->next;
        } 
        bool isEven = true;
        curr = head;
        while (!revOrderedLL.empty()) {
            ListNode* next = curr->next;
            ListNode* top = revOrderedLL.top(); 
            revOrderedLL.pop();
            curr->next = top;
            top->next = next;
            curr = next;
        }
    }
};
