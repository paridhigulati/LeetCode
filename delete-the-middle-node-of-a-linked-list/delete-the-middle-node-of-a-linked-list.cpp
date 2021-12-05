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
    ListNode* deleteMiddle(ListNode* head) {
      
               if(head ==NULL || head->next ==NULL) return NULL;
        
        ListNode* slow=head, *fast=head, *temp=head;
       // int n=0;
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
           // n+=2;
        }
//if(n==0) return NULL;
        if(slow->next) temp->next=slow->next;
        else temp->next=NULL;
        return head;
    }
};