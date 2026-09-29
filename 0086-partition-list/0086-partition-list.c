struct ListNode* partition(struct ListNode* head, int x) {
    // build two separate lists, one for small values and one for the rest,
    // then stitch them together at the end
    struct ListNode smallDummy;
    struct ListNode bigDummy;
    smallDummy.next = NULL;
    bigDummy.next = NULL;

    struct ListNode* small = &smallDummy;
    struct ListNode* big = &bigDummy;

    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            big->next = head;
            big = big->next;
        }
        head = head->next;
    }

    // very important: the last big node may still point into the small list,
    // so we have to cut it off or we would create a cycle
    big->next = NULL;

    // small list first, then the big list
    small->next = bigDummy.next;

    return smallDummy.next;
}
