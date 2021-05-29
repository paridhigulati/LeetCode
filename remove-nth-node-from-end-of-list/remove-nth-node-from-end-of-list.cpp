/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode();
        temp->next=head;
        ListNode* fast = temp;
        ListNode* slow = temp;
        
        for(int i=0;i<=n;i++)
        {
            fast=fast->next;
        }
        while(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next = slow->next->next;
        return temp->next;
    }
};
*/

// 2-pass approach , in 1st pass we are finding the length

  //  ListNode* removeNthFromEnd(ListNode* head, int n)
    /*
    {
        if(head==NULL || head->next ==NULL)
            return head;
        int count;
        ListNode* counter = head;
        while(counter)
        {
            counter=counter->next;
            count++;
        }
        int del = count - n;
        if(count == 1)
            return NULL;
            if(n>=count)
                return head->next;
        if(del < 0)
       return head->next; 
        counter = head;
        for(int i=1;i<del;i++)
        {
            counter = counter->next;
            counter->next = counter->next->next;
        }
        return head;
        }
    
};

*/





//1 pass approach w/o finding the length 

    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
       
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        ListNode* nth = dummy;
        
        for(int i=1;i<=n+1;i++)
        {
            curr=curr->next;
        }
        while(curr)
        {
            curr = curr->next;
            nth = nth->next;
        }
        nth->next = nth->next->next;
        return dummy->next;
    }

};













