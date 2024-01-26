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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }
        ListNode* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }
        current->next = head;
        k = k % length;
        for (int i = 0; i < length - k - 1; i++) {
            head = head->next;
        }
        ListNode* new_head = head->next;
        head->next = nullptr;
        return new_head;
    }
};