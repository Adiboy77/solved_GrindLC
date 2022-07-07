class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
       
    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;
    
    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }
     
        //Merging:
        p1 = head, p2 = head2;
        while(p1 && p2)//did && p2 for handling odd lengthed LL case
        {
            ListNode* temp = p1->next;
            p1->next = p2;
            ListNode* temp2 = p2->next;
            p2->next = temp;
            p1 = temp;
            p2 = temp2;
        }
        return;
    }
};
