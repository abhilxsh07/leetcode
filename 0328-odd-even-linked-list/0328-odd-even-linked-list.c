struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // the problem talks about positions (1st, 2nd, ...) not values
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = even; // remember where the even list starts

    while (even != NULL && even->next != NULL) {
        // odd skips over the even node to the next odd one
        odd->next = even->next;
        odd = odd->next;

        // same thing for the even list
        even->next = odd->next;
        even = even->next;
    }

    // attach the even list behind the odd list
    odd->next = evenHead;

    return head;
}
