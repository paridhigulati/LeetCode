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
    
    ListNode* midL(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast =  fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSortLL(ListNode* l1, ListNode* l2)
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        ListNode* c1 = l1;
        ListNode* c2 = l2;
     while(c1!=NULL && c2!=NULL)
        {
           if(c1->val < c2->val)
            {
                prev->next = c1;
                c1=c1->next;
            }
            else
            {
                prev->next = c2;
                c2=c2->next;
            }
            prev = prev->next;
            prev->next = c1!=NULL?c1:c2;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* mid = midL(head);
        ListNode* newHead = mid->next;  // divides the list into 2 halves
        mid->next =NULL ;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(newHead);
        return mergeSortLL(l1,l2);
    }
};