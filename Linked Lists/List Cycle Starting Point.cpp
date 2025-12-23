/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head) {
    if (!head || !head->next) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;
    bool hasCycle = false;

    // Determine if a cycle exists
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            hasCycle = true;
            break;
        }
    }

    // If no cycle was found, return NULL
    if (!hasCycle) return NULL;

    // Find the entry point of the cycle
    ListNode* iter = head;
    while(iter != slow) {
        slow = slow->next;
        iter = iter->next;
    }

    return iter;
}
