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
        ListNode* prev =NULL, *fwd=NULL;
        
        
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
        
        ListNode* start = head, *end=head;
        int cnt = k-1;
        while(cnt--)
        {
            end = end->next;
            if(end == NULL) 
                return head;
            
        }
        
       ListNode* newHead =  reverseKGroup(end->next, k);
        
         reverse(start, end);
        
        start->next = newHead;
        
        return end;
        
        
        
    }
};