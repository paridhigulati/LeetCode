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
  
    ListNode* getMid(ListNode* tmp)
    {
        ListNode* slow = tmp, *fast = tmp;
        
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head, *prev = NULL, *fwd;
        
        while(curr)
        {
            fwd = curr->next;
            curr->next = prev;
            prev  = curr;
            curr = fwd;
        }
        return prev;
    }
  
        
  public:      
    bool isPalindrome(ListNode* head) {

      if(head==NULL || head->next==NULL) return true;
        ListNode* tmp = head;
        
        ListNode* mid = getMid(tmp);
       ListNode* head2 = reverse(mid);
        
        while(head and head2)
        {
             cout<<head->val<< " " <<head->val;
            if(head->val !=head2->val)
            {
                return false;
                
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};
     
//     ListNode* reverseList(ListNode* head){
//         ListNode* prev=NULL,*curr=head,*temp=NULL;
//         while(curr != NULL){
//             temp=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=temp;
//         }
//         return prev;
//     }
//     bool compareList(ListNode* head1, ListNode* head2){
//         while(head1!=NULL && head2!=NULL){
//             if(head1->val != head2->val) return false;
//             head1=head1->next;
//             head2=head2->next;
//         }
//         return true;
//     }
//     bool isPalindrome(ListNode* head) {
//         if(head==NULL || head->next==NULL) return true;
//         ListNode* h=head;
//         ListNode* mid = findMid(h);
//         ListNode* h2=reverseList(mid);
//         return compareList(head,h2);
//     }
// };