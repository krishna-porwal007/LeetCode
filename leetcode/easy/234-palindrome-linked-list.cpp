/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        if (fast != nullptr) slow = slow -> next;
        while (slow != nullptr) {
            ListNode *temp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = temp;
        }
        ListNode *left = head;
        ListNode *right = prev;
        while (right != nullptr) {
            if (left -> val != right -> val) return false;
            left = left -> next;
            right = right -> next;
        }
        return true;
    }
};