struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    // nothing to reverse when left and right are the same position
    if (head == NULL || left == right) {
        return head;
    }

    // dummy node in case left is 1 and the head itself moves
    struct ListNode dummy;
    dummy.next = head;

    // walk to the node just before the section we want to reverse
    struct ListNode* prev = &dummy;
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // curr stays glued to the first node of the section,
    // and it slowly gets pushed to the back as we pull nodes in front of it
    struct ListNode* curr = prev->next;
    for (int i = 0; i < right - left; i++) {
        struct ListNode* nextNode = curr->next;

        // take nextNode out of its spot...
        curr->next = nextNode->next;
        // ...and drop it in right after prev
        nextNode->next = prev->next;
        prev->next = nextNode;
    }

    return dummy.next;
}
