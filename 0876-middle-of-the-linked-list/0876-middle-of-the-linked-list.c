struct ListNode* middleNode(struct ListNode* head) {
    // fast moves twice as quickly as slow, so when fast finishes
    // slow is standing right in the middle
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // for an even length this lands on the second middle node,
    // which is exactly what the problem asks for
    return slow;
}
