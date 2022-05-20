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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*brute: count the nodes O(n)
	ListNode* iter = head;
	int len = 0, i = 1;
	while(iter)
    iter = iter -> next, len++;    // finding the length of linked list
	if(len == n) 
        
    return head -> next;          // if head itself is to be deleted, just return head -> next
	for(iter = head; i < len - n; i++)
      iter = iter -> next; // iterate first len-n nodes
	iter -> next = iter -> next -> next;      // remove the nth node from the end
	return head;
    }
};*/
        //OPTIMAL 1 PASS -> SLOW AND FAST POINTERS 
        
        //Now, between the fast and slow pointers, there is a gap of n nodes. Now, just Iterate and increment both the pointers till fast reaches the last node. The gap between fast and slow is still of n nodes, meaning that slow is nth node from the last node (which currently is fast).
        
	ListNode *fast = head, *slow = head;
	while(n--)
    fast = fast -> next;      // iterate first n nodes using fast
	if(!fast)
    return head -> next;       // if fast is already null, it means we have to delete head itself. So, just return next of head
	while(fast -> next)                  // iterate till fast reaches the last node of list
	fast = fast -> next, slow = slow -> next;            
	 slow -> next = slow -> next -> next; // remove the nth node from last
        //delete slow->next;
	return head;
}
};