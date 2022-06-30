/*
Brute Force: Using linear space by vectors:
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        temp = head;
        int i = 0;
        while(temp)
        {
            temp->val = v[i];
            i++;
            temp=temp->next;
        }
    return head;
    }
};
 */
/*
Bottom Up merge sort:
Algorithm

Assume, nn is the number of nodes in the linked list.

Start with splitting the list into sublists of size 11. Each adjacent pair of sublists of size 11 is merged in sorted order. After the first iteration, we get the sorted lists of size 22. A similar process is repeated for a sublist of size 22. In this way, we iteratively split the list into sublists of size 1,2,4,8 ..1,2,4,8.. and so on until we reach nn.

To split the list into two sublists of given \text{size}size beginning from \text{start}start, we use two pointers, \text{mid}mid and \text{end}end that references to the start and end of second linked list respectively. The split process finds the middle of linked lists for the given \text{size}size.

Merge the lists in sorted order as discussed in Approach 1

As we iteratively split the list and merge, we have to keep track of the previous merged list using pointer \text{tail}tail and the next sublist to be sorted using pointer \text{nextSubList}nextSubList.

Time Complexity: \mathcal{O}(n \log n)O(nlogn), where nn is the number of nodes in linked list. Let's analyze the time complexity of each step:
Count Nodes - Get the count of number nodes in the linked list requires \mathcal{O}(n)O(n) time.

Split and Merge - This operation is similar to Approach 1 and takes \mathcal{O}(n \log n)O(nlogn) time.
Space: O(1)
*/
class Solution {
public:
    ListNode* tail = new ListNode();
    ListNode* nextSubList = new ListNode();

    ListNode* sortList(ListNode* head) {
        if (!head || !head -> next)
            return head;
        int n = getCount(head);
        ListNode* start = head;
        ListNode dummyHead(0);
        for (int size = 1; size < n; size = size * 2) {
            tail = &dummyHead;
            while (start) {
                if (!start->next) {
                    tail->next = start;
                    break;
                }
                ListNode* mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead.next;
        }
        return dummyHead.next;
    }

    ListNode* split(ListNode* start, int size) {
        ListNode* midPrev = start;
        ListNode* end = start->next;
        //use fast and slow approach to find middle and end of second linked list
        for (int index = 1; index < size && (midPrev->next || end->next); index++) {
            if (end->next) {
                end = (end->next->next) ? end->next->next : end->next;
            }
            if (midPrev->next) {
                midPrev = midPrev->next;
            }
        }
        ListNode* mid = midPrev->next;
        nextSubList = end->next;
        midPrev->next = nullptr;
        end->next = nullptr;
        // return the start of second linked list
        return mid;
    }

    void merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* newTail = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                newTail->next = list1;
                list1 = list1->next;
                newTail = newTail->next;
            } else {
                newTail->next = list2;
                list2 = list2->next;
                newTail = newTail->next;
            }
        }
        newTail->next = (list1) ? list1 : list2;
        // traverse till the end of merged list to get the newTail
        while (newTail->next) {
            newTail = newTail->next;
        }
        // link the old tail with the head of merged list
        tail->next = dummyHead.next;
        // update the old tail with the new tail of merged list
        tail = newTail;
    }

    int getCount(ListNode* head) {
        int cnt = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            cnt++;
        }
        return cnt;
    }
};
