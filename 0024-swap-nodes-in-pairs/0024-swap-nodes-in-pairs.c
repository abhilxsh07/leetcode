struct ListNode* swapPairs(struct ListNode* head) {
    // dummy node again, since the head itself changes when we swap the first pair
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    // we need two nodes available to make a swap
    while (prev->next != NULL && prev->next->next != NULL) {
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;

        // rewire: prev -> second -> first -> (rest of the list)
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // first is now the second in the pair, so it is the new prev
        prev = first;
    }

    return dummy.next;
}
