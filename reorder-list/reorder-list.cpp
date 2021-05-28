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
    
   //REVERSE
   ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev =NULL;
            ListNode* fwd = NULL;
        while(curr)
        {
            fwd  = curr->next;
            curr->next = prev;
            prev = curr;
            curr=fwd;
        }
        return prev;
    }
    //MIDDLE
    ListNode* midL(ListNode* head) {
       if(head==NULL || head->next==NULL)
           return head;
         ListNode* slow = head;
    ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    
    
    ListNode* reorderList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        
    ListNode* mid = midL(head);
    ListNode* newHead = mid->next;
    mid->next=NULL;
    newHead = reverse(newHead);
     ListNode* c1 =head;
     ListNode* c2 = newHead;
         ListNode* f1=NULL;
         ListNode* f2 =NULL;
        
     while(c2!=NULL)
     {
    //BACKUP
      ListNode* f1 = c1->next;
      ListNode* f2 = c2->next;
   
        //LINKS
    c1->next = c2;
    c2->next = f1;
    //MOVE
    c1 = f1;
    c2=f2;
     }
        
        return head;
}        

};
