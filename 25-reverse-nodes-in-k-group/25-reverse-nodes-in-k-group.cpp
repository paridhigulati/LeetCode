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
    
    void reverse(ListNode* start, ListNode* end)
    {
        
        ListNode* curr = start;
        ListNode* prev =NULL, *fwd;
        
        
        while(prev !=end)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
 
    }    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
     
        if(head==NULL || head->next == NULL || k==1) return head;
         
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* end = head;
        ListNode* prev = dummy;
        
        int itr =0;
        while(end != NULL)
        {
            itr++;
            
            if(itr % k == 0)
            {
                ListNode* start = prev->next;
                ListNode* fwd = end->next; 
                reverse(start, end);
                
                start->next = fwd; 
                prev->next = end;
                
                
                prev = start; 
                end = fwd;
                
                
            }
            else{
                end = end->next;
            }
            
        }
        return dummy->next;
    }
};
        