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
    ListNode* partition(ListNode* head, int x) {
     
        
        ListNode* l1 = new ListNode(0);
        ListNode* l2 = new ListNode(0);
        
       
        ListNode* leftHead = l1;
        ListNode* rightHead = l2;
        
        
        if(head == NULL || head->next ==NULL)
        {
            return head;
        }
        
        while(head)
        {
            if(head->val < x)
            {
                l1->next = head;
                l1 = l1->next;
            }
            else
            {
                l2->next = head;
                l2 = l2->next;
            }
            
            head = head->next;
            if(head == NULL)
           l2 -> next = NULL;
        }
        l1->next = rightHead->next;
        
        return leftHead->next;
    }
};
        
       
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        