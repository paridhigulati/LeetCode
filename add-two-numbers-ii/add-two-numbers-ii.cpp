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
    
/*   ListNode* reverse(ListNode* head)
    {
       if(head==NULL||head->next==NULL)
           return head;
        ListNode* prev = head;
        ListNode* curr = NULL;
            ListNode* fwd = NULL;
        while(curr)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
       ListNode* c1= reverse(l1);
        ListNode* c2 = reverse(l2);
        int carry=0;
        while(c1!=NULL || c2!=NULL || carry)
        {
            int sum=0;
            if(c1)
            
      {
          sum+=c1->val;
          c1=c1->next;
      }
      if(c2)
      {
          sum+=c2->val;
          c2=c2->next;
      }
        
        sum+=carry;
        carry = sum/10;
        ListNode* node = new ListNode(sum%10);
        temp->next = node;
        temp = temp->next;
    }
    
        return reverse(temp->next);
}
};
*/
/*

 ListNode* reverse(ListNode *head){
        ListNode *curr=head,*prev=NULL,*fwd=NULL;
        while(curr){
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode *dummy = new ListNode();
        ListNode *temp=dummy;
        int carry=0;
        
        while(l1 || l2 || carry){
            int sum=0;
            if(l1){
                sum +=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;   
        }
        return reverse(dummy->next);
    }
}; */



// WITHOUT REVERSE 


    int findLength(ListNode *root) {
        int res = 0;
        while (root) {
            res++;
            root = root->next;
        }
        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // support variables
        bool hasRem = false;
        int len1 = findLength(l1), len2 = findLength(l2), pos = 0;
        pair<ListNode*, ListNode*> store[100];
        // making sure l1 is not smaller
        if (len1 < len2) {
            swap(l1, l2);
            swap(len1, len2);
        }
        // main loop to read
        while (len1--) {
            // storing the explored value, having l2 advance only when len2 >= len1
            store[pos++] = {l1, len2 <= len1 ? NULL : l2};
            l1 = l1->next;
            l2 = len2 <= len1 ? l2 : l2->next;
        }
        // main loop to write
        while (pos--) {
            l1 = store[pos].first;
            l2 = store[pos].second;
            l1->val += hasRem + (l2 ? l2->val : 0);
            hasRem = l1->val > 9;
            l1->val %= 10;
        }
        // last touch: we need to add a node on top if we still had a remainder
        if (hasRem) {
            l2 = new ListNode(1);
            l2->next = l1;
            l1 = l2;
        }
        return l1;
    }
};