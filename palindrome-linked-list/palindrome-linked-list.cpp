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
    
    // FIND MIDDLE,  REVERSE THE SECOND HALF AND THEN COMPARE
ListNode* reverse (ListNode* slow)
{ 
    
    ListNode* next=NULL;
    ListNode* prev=NULL;
    while(slow!=NULL)
    {
    
    
    next = slow->next;
    slow->next = prev;
    prev = slow;
    slow=next;
     }
    return prev;
}
    bool isPalindrome(ListNode* head) {
                 
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=head;
        slow = reverse(slow);
        while(slow!=NULL)
        {
            if(fast->val!=slow->val)
            {return false;}
            fast=fast->next;
            slow=slow->next;
            
        }
        return true;
    }
};