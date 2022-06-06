/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
        Infact, we don't need to find diff and iterate the greater length list. Instead, if we reach the end of a list, just restart from the head of other list. This can help up counter the difference of lengths. Finally, the lists will either converge on intersected node or both will reach end at same time and we will return NULL at last.

For eg. Lists having intersected node (Example 1 from description) -

A : 4 -> 1 -> 8 -> 4 -> 5 |  5 -> 6 -> 1 -> 8 <- same node found
						  ^end(restart from B)
B : 5 -> 6 -> 1 -> 8 -> 4 -> 5 |  4 -> 1 -> 8 <- same node found
							   ^end(restart from A)
return since we found the same node*/
        if(headA==NULL ||headB ==NULL)
        
            return NULL;  
        ListNode* a  = headA;
        ListNode* b = headB;
        while(a!=b)
        {
          a = a==NULL?headB:a->next;
            b= b==NULL?headA: b->next;
        }
        return b;
    }
};