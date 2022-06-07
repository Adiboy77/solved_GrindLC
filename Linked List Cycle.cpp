class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow && fast)
        {
            if(slow == fast)
                break;
            if(fast->next)
            {
                 slow = slow->next;
                 fast = fast->next->next;
            }
            else 
                break;
        }
        if(slow == fast && slow)
            return true;
        else
            return false;
    }
};
