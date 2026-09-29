/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    // 1. Find the middle using slow/fast pointers
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse the second half in place
    struct ListNode *prev = NULL;
    while (slow) {
        struct ListNode *nxt = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nxt;
    }

    // 3. Compare first half with reversed second half
    struct ListNode *l = head, *r = prev;
    while (r) {
        if (l->val != r->val) return false;
        l = l->next;
        r = r->next;
    }
    return true;
}
