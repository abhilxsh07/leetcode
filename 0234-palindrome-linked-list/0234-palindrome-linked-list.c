bool isPalindrome(struct ListNode* head) {
    // a list with 0 or 1 nodes reads the same both ways
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // step 1: find the middle using slow and fast pointers
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // step 2: reverse everything after the middle
    struct ListNode* prev = NULL;
    struct ListNode* curr = slow->next;
    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // step 3: compare the first half with the reversed second half
    struct ListNode* left = head;
    struct ListNode* right = prev;
    while (right != NULL) {
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }

    return true;
}
