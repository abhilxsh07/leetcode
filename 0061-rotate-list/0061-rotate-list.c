struct ListNode* rotateRight(struct ListNode* head, int k) {
    // nothing to rotate if the list is empty, has one node, or k is 0
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    // walk to the tail while counting how many nodes we have
    int len = 1;
    struct ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    // rotating by len brings us back to the start, so only the remainder matters
    k = k % len;
    if (k == 0) {
        return head;
    }

    // the new tail is the node at position len - k - 1 (0-indexed)
    struct ListNode* newTail = head;
    for (int i = 0; i < len - k - 1; i++) {
        newTail = newTail->next;
    }

    // the node after it becomes the new head
    struct ListNode* newHead = newTail->next;

    // cut the list there, then glue the old tail back onto the old head
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}
