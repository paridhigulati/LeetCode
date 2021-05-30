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
   
        /*We can directly swap the values of kth node and kthFromEnd node in a single pass. We will use a temp pointer to iterate over the linked list.

We will first iterate till the kth node  and assign this to the kthNode pointer.

Initialise the kthNodeFromEnd (slow) pointer to the given head of list. Now, the gap between the iter and kthNodeFromEnd is k (since we have already iterated the iter pointer k times). Just iterate both the pointers, till iter reaches the last node. The gap between them will still be k meaning kthNodeFromEnd is correctly at its position.

Just swap the values and return head pointer.*/

ListNode* swapNodes(ListNode* head, int k) {        
	ListNode *kthNode, *kthNodeFromEnd = head, *temp = head;
	while(--k)
		temp = temp -> next;
	kthNode = temp;
	while(temp -> next)
		temp = temp -> next, kthNodeFromEnd = kthNodeFromEnd -> next;
	swap(kthNode -> val, kthNodeFromEnd -> val);
	return head;
    }
        
    
};