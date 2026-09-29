struct ListNode* deleteDuplicates(struct ListNode* head) {
    // dummy node because the head itself might be a duplicate and get removed
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (prev->next != NULL) {
        struct ListNode* curr = prev->next;

        if (curr->next != NULL && curr->val == curr->next->val) {
            // found a run of duplicates, remember the value we are deleting
            int dupVal = curr->val;

            // skip every node that carries that value
            while (curr != NULL && curr->val == dupVal) {
                curr = curr->next;
            }

            // prev now jumps over the whole run
            prev->next = curr;
        } else {
            // this value is unique, keep it and move on
            prev = curr;
        }
    }

    return dummy.next;
}
