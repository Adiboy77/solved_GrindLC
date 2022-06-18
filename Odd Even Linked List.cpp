/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
Same but simpler to understand code:
  public ListNode oddEvenList(ListNode head) {
        if (head == null) return null;
        ListNode odd = head, even = head.next, evenHead = even;
        while (even != null && even.next != null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = evenHead;
        return head;
    }
*/
//Own code:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* oH = head, *eH = head->next;
        ListNode*eH2 = eH;//temporary even head copy to attach it later on to odd's tail
        while(eH && eH->next)
        {
            oH->next = eH->next;
            oH = oH->next;
            if(oH && oH->next)
            {
                eH->next = oH->next;
                eH = eH->next;
            }
            else
            {
                eH->next = NULL;//for odd lengthed case
                oH->next = eH2;//attaching even's head back to the odd's tail
                break;
            }   
        }
        if(eH && eH->next==NULL)//for even lenghted case
            oH->next = eH2;//attaching even's head back to the odd's tail
        return head;
    }
};
