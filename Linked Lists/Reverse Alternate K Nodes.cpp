/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head, ListNode* end) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    while (curr != end) {
        ListNode* nextNodes = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNodes;
    }
    return prev;
}
ListNode* Solution::solve(ListNode* head, int k) {
    if (head == NULL) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* curr = dummy;
    bool alternateL = true;
    while (true) {
        ListNode* prevGroup = curr;
        ListNode* end = curr;
        int cnt = 0;
        while (cnt < k && end->next) {
            cnt++;
            end = end->next;
        }
        if (cnt == 0) break;
        if (alternateL) {
            ListNode *start = curr->next;
            ListNode *nextGroup = end->next;
            ListNode *revLL = reverse(start, nextGroup);
            prevGroup->next = end;
            start->next = nextGroup;
            curr = start;
        } else curr = end;
        alternateL = !alternateL;
    }
    return dummy->next;
}
