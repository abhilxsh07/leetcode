void deleteNode(struct ListNode* node) {
    // we are not given the head, so we cannot fix the previous node's pointer.
    // trick: copy the next node's value into this one, then skip the next node.
    // the value we wanted to delete is overwritten, so it is effectively gone.
    node->val = node->next->val;
    node->next = node->next->next;
}
