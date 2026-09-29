struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // a dummy node saves us from special-casing the very first node
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;

    // keep picking whichever front node is smaller
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // one list ran out, the other one is already sorted so just hook it on
    tail->next = (list1 != NULL) ? list1 : list2;

    // skip the dummy, the real answer starts after it
    return dummy.next;
}
