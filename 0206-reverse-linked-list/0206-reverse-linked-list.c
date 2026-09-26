struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *cur = head, *nxt;

    while (cur) {
        nxt = cur->next;   // keep the rest
        cur->next = prev;  // point it back
        prev = cur;
        cur = nxt;
    }
    return prev;
}