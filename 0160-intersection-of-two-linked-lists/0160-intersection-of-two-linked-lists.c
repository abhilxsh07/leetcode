struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    struct ListNode *a = headA;
    struct ListNode *b = headB;

    // each pointer walks its own list, then jumps to the start of the other one.
    // both end up travelling lenA + lenB steps, so if the lists share a tail
    // they land on the intersection at the same time. if not, both hit NULL together.
    while (a != b) {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }

    return a;
}
