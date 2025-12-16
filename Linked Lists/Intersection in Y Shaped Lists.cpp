#include <iostream>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
int getLength(ListNode* head) {
    int len = 0;
    ListNode* iter = head;
    while (iter != NULL) {
        len++;
        iter = iter->next;
    }
    return len;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int nA = getLength(headA);
    int nB = getLength(headB);
    if (nA > nB) {
        int extra = nA - nB;
        while (extra) {
            headA = headA->next;
            extra--;
        }
    } else if (nB > nA) {
        int extra = nB - nA;
        while (extra) {
            headB = headB->next;
            extra--;
        }
    }

    while (headA && headB) {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return nullptr;
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Common part: 7 -> 9 -> 11
    ListNode* common = new ListNode(7);
    common->next = new ListNode(9);
    common->next->next = new ListNode(11);

    // List A: 1 -> 3 -> 5 -> 7 -> 9 -> 11
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(3);
    headA->next->next = new ListNode(5);
    headA->next->next->next = common;

    // List B: 2 -> 7 -> 9 -> 11
    ListNode* headB = new ListNode(2);
    headB->next = common;

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    ListNode* ans = getIntersectionNode(headA, headB);

    if (ans)
        cout << "Intersection at node value: " << ans->val << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}
