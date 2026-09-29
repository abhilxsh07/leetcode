struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr = head;

    // the list is sorted, so duplicates always sit right next to each other
    while (curr != NULL && curr->next != NULL) {
        if (curr->val == curr->next->val) {
            // same value as the next node, so cut the next one out
            struct ListNode* dup = curr->next;
            curr->next = dup->next;
            free(dup);
        } else {
            // different value, safe to move on
            curr = curr->next;
        }
    }

    return head;
}
