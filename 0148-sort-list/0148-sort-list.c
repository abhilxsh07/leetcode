// small helper: merge two already sorted lists into one sorted list
struct ListNode* mergeSorted(struct ListNode* a, struct ListNode* b) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;

    while (a != NULL && b != NULL) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    // whatever is left is already sorted
    tail->next = (a != NULL) ? a : b;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    // base case: 0 or 1 nodes is already sorted
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // find the middle. fast starts one step ahead so that for even lengths
    // slow ends on the last node of the first half
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // cut the list into two halves
    struct ListNode* right = slow->next;
    slow->next = NULL;

    // sort each half on its own, then merge them (plain merge sort)
    struct ListNode* leftSorted = sortList(head);
    struct ListNode* rightSorted = sortList(right);

    return mergeSorted(leftSorted, rightSorted);
}
