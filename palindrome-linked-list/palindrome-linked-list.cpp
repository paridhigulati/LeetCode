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
/* Linked list is odd length - There will be single middle element at which the slow pointer will point to at the end of iteration  In case of odd length which can be known if fast pointer doesn't end at null ends, we just iterate slow pointer forward by 1. We then just compare linked lists starting at prev and slow and return true if the lists are equal, else false. */
 /*   ListNode* middle(ListNode* head)
    {
         ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;

        }
        return slow;
    }
    
    ListNode* revList(ListNode* newHead)
    {
        if(newHead==NULL and newHead->next==NULL)
        {
            return newHead;
        }
        ListNode* curr = newHead;
        ListNode* prev = NULL;
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
    
    

    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
         ListNode* slow=head;
        ListNode* fast=head;
        ListNode* mid = middle(head);
         
         ListNode* reverse = revList(slow);
        while(reverse!=NULL){
            if(head->val!=reverse->val)
                return false;
            head=head->next;
            reverse=reverse->next;
        }
        return true;
    }
    };

*/
bool isPalindrome(ListNode* head) {
        ListNode* slow(head);
        ListNode* fast(head);
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head; 
        slow = reverse(slow); 
        while(slow)
        {
           if(fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* curr)
    {
        ListNode* prev(NULL);
        while(curr)
        {
            ListNode* fwd = curr->next;
            curr->next = prev;
            prev= curr;
            curr = fwd;
        }
        return prev;
    }
};