void reorderList(struct ListNode* head) {
    // lists with fewer than 3 nodes are already in the right order
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }

    // step 1: find the middle of the list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // step 2: split into two halves and reverse the second one
    struct ListNode* second = slow->next;
    slow->next = NULL;

    struct ListNode* prev = NULL;
    while (second != NULL) {
        struct ListNode* nextNode = second->next;
        second->next = prev;
        prev = second;
        second = nextNode;
    }
    second = prev;

    // step 3: weave them together, one from the front, one from the back
    struct ListNode* first = head;
    while (second != NULL) {
        struct ListNode* firstNext = first->next;
        struct ListNode* secondNext = second->next;

        first->next = second;
        second->next = firstNext;

        first = firstNext;
        second = secondNext;
    }
}
