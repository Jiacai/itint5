using namespace std;
//对一个单链表原地（in-place）排序。即直接对链表结点排序。返回排序后链表的头结点。

//struct ListNode {
//    int val;
//    ListNode *next;
//}

ListNode* mergeSort(ListNode *node, int size) {
    if (size == 0 || size == 1)
        return node;
    int half = size / 2;
    ListNode* head1 = node;
    ListNode* head2 = node;
    for (int i = 0; i < half; i++) {
        head2 = head2->next;
    }
    head1 = mergeSort(head1, half);
    head2 = mergeSort(head2, size - half);

    ListNode *dummy = new ListNode();
    ListNode *prev = dummy;
    ListNode *n1 = head1;
    ListNode *n2 = head2;
    int n1Step = 0;
    int n2Step = 0;
    while (n1Step != half && n2Step != size - half) {
        if (n1->val <= n2->val) {
            prev->next = n1;
            n1 = n1->next;
            n1Step++;
        }
        else {
            prev->next = n2;
            n2 = n2->next;
            n2Step++;
        }
        prev = prev->next;
    }
    while (n2Step != size - half) {
        prev->next = n2;
        prev = prev->next;
        n2 = n2->next;
        n2Step++;
    }
    while (n1Step != half) {
        prev->next = n1;
        prev = prev->next;
        n1 = n1->next;
        n1Step++;
    }
	prev->next = NULL;
    return dummy->next;
}


ListNode* sortLinkList(ListNode *head) {
    int size = 0;
    ListNode *node = head;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return mergeSort(head, size);
}