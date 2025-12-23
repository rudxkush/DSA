#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printLL(ListNode* head) {
    ListNode* iter = head;
    while (iter != NULL) {
        cout << iter->val;
        if (iter->next) cout << " -> ";
        iter = iter->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* stop) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != stop) {
            ListNode* nextNodes = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNodes;
        }
        return prev;
    }
    ListNode* reverseAlternateKGroups(ListNode* head, int k) {
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
};


int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next->next = new ListNode(4);

    cout << "Input LL: " << endl;
    printLL(head);

    Solution obj;
    head = obj.reverseAlternateKGroups(head, 3);

    cout << "Output LL: " << endl;
    printLL(head);
    return 0;
}
