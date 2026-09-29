struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // dummy in front so removing the head is not a special case
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // give fast a head start of n steps
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // now move both together until fast is on the last node,
    // slow will be right before the one we want to delete
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // unlink the target node and free it so we do not leak memory
    struct ListNode* target = slow->next;
    slow->next = target->next;
    free(target);

    return dummy.next;
}
