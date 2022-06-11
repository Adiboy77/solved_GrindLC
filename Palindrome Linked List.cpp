//We would reverse the first half of the LL & then compare from mid-point along either sides
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = NULL, *next = NULL;
        while(fast && fast->next)//This loop is for finding the mid-point of LL & reversing the LL up until the mid-point head till prev is reversed, slow till NULL is as it is & slow points to mid-point of LL.
        {
            fast = fast->next->next;
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        if(fast && fast->next == NULL)//odd lengthed case
        {
            slow = slow->next;
        }
        while(prev && slow)
        {
            if(prev->val != slow->val)
                return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};
