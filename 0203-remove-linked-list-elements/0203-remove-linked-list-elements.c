struct ListNode* removeElements(struct ListNode* head, int val) {
    // dummy node so we do not need a separate case for removing the head
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* curr = &dummy;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            // the next node is one we want gone, so skip over it.
            // we do not move curr yet because the new next might also match
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}
