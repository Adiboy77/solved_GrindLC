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
//Learnt that make sure you check what you are returning, so keep a copy of head pointer to return.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out = new ListNode();
        ListNode* ans = out;
        int carry = 0, prevCarry = (l1->val + l2->val) / 10;;
        out->val = (l1->val + l2->val) % 10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 || l2)
        {
            int sum = 0;
            if(l1)
            {
                 sum += l1->val;
                 l1 = l1->next;
            }
            if(l2)
            {
                 sum += l2->val;
                 l2 = l2->next;
            }
            carry = ( (sum + prevCarry) / 10 );
            sum = ( (sum + prevCarry) % 10 );
            ListNode* ns = new ListNode(sum);
            out->next = ns;
            out = out->next;
            prevCarry = carry;
        }
        if(prevCarry)
        {
            ListNode* ns = new ListNode(prevCarry);
            out->next = ns;
        }
        return ans;
    }
};
