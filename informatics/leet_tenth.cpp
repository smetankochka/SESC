ListNode* partition(ListNode* head, int x) {
    ListNode* beforeHead = new ListNode();
    ListNode* afterHead = new ListNode();
    ListNode* before = beforeHead;
    ListNode* after = afterHead;

    while (head != nullptr) {
        if (head->val < x) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }

    after->next = nullptr;
    before->next = afterHead->next;

    return beforeHead->next;
}