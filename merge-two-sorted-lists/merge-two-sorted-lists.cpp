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
          ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
              
            if(l1==NULL)
                return l2;
              if(l2==NULL)
                  return l1;
              
              ListNode* c1 = l1;
              ListNode* c2 = l2;
              ListNode* dummy = new ListNode(-1);
              ListNode* prev = dummy;
              while(c1!=NULL && c2!=NULL) // O(N+M)
              {
                  if(c1->val <= c2->val )
                  {
                      prev->next = c1;
                      c1=c1->next;
                  }
                  else
                  {
                      prev->next = c2;
                      c2 = c2->next;
                  }
                  prev = prev->next;
              }
              //Now we need to merge the longer sorted list 
            prev->next=c1!=NULL?c1:c2;  // aage ki list apne aap attach ho jaegi pehle ki list se 
           return dummy->next;  
          }
};
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
/*      
        
        ListNode *head=NULL;
        ListNode*tail=NULL;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                if(!head) {
                    head=l1;
                    tail=l1;
                } else {
                    tail->next = l1;
                    tail=tail->next;
                }
                l1=l1->next;
            } else {
                if(!head) {
                    head=l2;
                    tail=l2;
                } else {
                    tail->next = l2;
                    tail=tail->next;
                }
                l2=l2->next;
            }
        }
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        return head;
    }
        
    
}; */