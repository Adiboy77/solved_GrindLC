/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*Alternate solution:
ListNode* reverseList(ListNode* head) 
{
	ListNode* prev = NULL;
	ListNode* follow = NULL;
	while (head)
	{
		follow = head->next;
		head->next = prev;
		prev = head;
		head = follow;
	}
    return prev;
}
bool hasCycle(ListNode *head)
{
	ListNode* rev = reverseList(head);
	if (head && head->next && rev == head)
	{
		return true;
	}
	return false;
}
if the list has got a loop, then its reversed version must have got the same head pointer as its self;
*/
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
