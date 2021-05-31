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
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        ListNode* Lhead = left;
        ListNode* Rhead = right;
        if(head==NULL || head->next==NULL)
            return head;
        while(head )
        {
            if(head->val < x)
            {
                left->next = head;
                left = left->next;
              
            }
            else
            {
                right->next = head;
                right = right->next;
                 
            }
            head = head->next;
            if(head == NULL)
                right->next = NULL;
            
        }
      
        left->next = Rhead->next;
        return Lhead->next;
    }
};