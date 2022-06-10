class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while(fast)
        {
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                break;
        }
        return slow;
    }
};
