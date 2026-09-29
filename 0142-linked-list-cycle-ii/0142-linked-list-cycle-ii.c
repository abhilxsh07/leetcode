struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // phase 1: figure out whether there is a cycle at all
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // phase 2: there is a cycle. restart one pointer from the head and move
            // both at the same speed, they meet exactly where the cycle begins
            struct ListNode *start = head;
            while (start != slow) {
                start = start->next;
                slow = slow->next;
            }
            return start;
        }
    }

    // fast hit the end, so no cycle
    return NULL;
}
