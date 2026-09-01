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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head;
        ListNode *cur = head -> next;
        int idx = 1;
        int first = -1, last = -1;
        int mn = INT_MAX;
        while (cur -> next != nullptr) {
            ListNode *next = cur -> next;
            bool maxima = cur -> val > prev -> val && cur -> val > next -> val;
            bool minima = cur -> val < prev -> val && cur -> val < next -> val;
            if (maxima || minima) {
                if (last == -1) first = idx;
                else mn = min(mn, idx - last);
                last = idx;
            }
            prev = cur;
            cur = next;
            idx++;
        }
        if (first == -1 || first == last) return {-1, -1};
        return {mn, last - first};
    }
};