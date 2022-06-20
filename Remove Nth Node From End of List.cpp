class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t1 = head;
        ListNode* t2 = head;
        int tn = n;
        while(tn--)//we moved n from beginning
            t1 = t1->next;
        if(!t1)
            return head->next;//n == length(list) i.e., deleting first node from beginning
        else if(t1 == head)//n == 0
            return head;
        while(t1->next)//this loop is for the logic that: to move n from end(with t2) = n - (moved n from beginning(that we did in 1st while loop with t1))
        {
            t2 = t2->next;
            t1 = t1->next;
        }
        //Now we have to delete the element t2->next
        if(t2->next->next)
            t2->next = t2->next->next;//n > 1 & n < length(list)
        else
            t2->next = NULL;//n == 1
        return head;
    }
};
