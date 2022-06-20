//Similarly no need for implementing rotate LL left because, rotating right by k == rotating left by (n-k), and vice versa, plus the order of the nodes remain same except the oldHead may come right after oldTail
class Solution {
public:
    //In the below code, we just find the kth element from the end, make it the new head, and then append tail to the oldHead.
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k)
            return head;
        int len = 0;
        ListNode* temp = head, *tail = NULL;
        while(temp)
        {
            len++;
            if(!temp->next)
                tail = temp;//stores the last node 
            temp = temp->next;
        }
        k = k % len;//As k <= 2*10^9, so we do k = k%n
        if(k == 0)
            return head;
        int nfg = len - k;//nfg denotes node from beginning
        temp = head;
        while(--nfg)
            temp = temp->next;
        ListNode *newHead = temp->next;//temp->next always exits because as k now ranges from 1 to len-1 , so nfg ranges from 1 to n-1th node, thus temp->next always exists.
        temp->next = NULL;
        tail->next = head;
        return newHead;
    }
};
