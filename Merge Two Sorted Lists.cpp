/*using extra space:
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        if(list1->val <= list2->val)
        {
            ans->val = list1->val;
            list1 = list1->next;
        }
        else
        {
            ans->val = list2->val;
            list2 = list2->next;
        }
        while(list1 && list2)
        {
                if(list1->val <= list2->val)
                {
                    ListNode* ns = new ListNode(list1->val);
                    ans->next = ns;
                    ans = ans->next;
                    list1 = list1->next;
                }
                else
                {
                    ListNode* ns = new ListNode(list2->val);
                    ans->next = ns;
                    ans = ans->next;
                    list2 = list2->next;
                }
        }
        if(list1)
            ans->next = list1;
        if(list2)
            ans->next = list2;
        return temp;
    }
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val > list2->val) swap(list1, list2);
        ListNode * res = list1;
        while(list1 != NULL && list2 != NULL)
        {
            ListNode * temp = NULL;
            while(list1 != NULL && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return res;
    }
};
