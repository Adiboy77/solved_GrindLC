class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* slow = head, *fast = head->next, *prev = NULL, *ans = head->next;
        while(slow && fast)
        {
            slow->next = fast->next;
            fast->next = slow;
            if(prev)
                prev->next = fast;
            prev = slow;   
            slow = slow->next;
            if(slow)
            fast = slow->next;
        }
        return ans;
    }
};
