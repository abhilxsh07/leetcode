struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // digits are stored in reverse, so we can add from the front just like
    // doing addition by hand on paper
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
    int carry = 0;

    // keep going while there are digits left OR a leftover carry
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        // the digit we keep is sum % 10, the rest carries over
        carry = sum / 10;

        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;

        tail->next = node;
        tail = node;
    }

    return dummy.next;
}
