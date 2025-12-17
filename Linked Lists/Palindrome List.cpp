#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the LL from the middle
        ListNode* second = (fast ? slow->next : slow);
        second = reverse(second);
        // printList(head);

        // Compare both the halves
        ListNode* iterLL = head;
        while(second != NULL) {
            if(iterLL->val != second->val) {
                return false;
            }
            iterLL = iterLL->next;
            second = second->next;
        }
        return true;
    }
};
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    cout << "Original list: ";
    printList(head);

    Solution obj;
    bool ans = obj.isPalindrome(head);
    if (ans) {
        cout << "LL is palindrome" << endl;
    } else {
        cout << "LL is not a palindrome" << endl;
    };

    return 0;
}
