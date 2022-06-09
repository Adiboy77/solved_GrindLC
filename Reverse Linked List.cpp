class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head, *prev = NULL, *next = NULL;
        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
};
