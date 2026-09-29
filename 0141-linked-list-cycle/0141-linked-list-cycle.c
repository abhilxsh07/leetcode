bool hasCycle(struct ListNode *head) {
    // classic tortoise and hare: slow moves 1 step, fast moves 2
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // if fast reaches the end, the list is straight and has no loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // if there is a loop, fast will eventually lap slow and they meet
        if (slow == fast) {
            return true;
        }
    }

    return false;
}
