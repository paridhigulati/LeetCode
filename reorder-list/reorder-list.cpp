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



/*Find Middle Node in Linked List
Reverse a Linked List
Start from the first list and alternatively add elements from both the lists.
    */


/*
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
        if(head==NULL || head->next==NULL) //edge case, always check this 
            return head;
        
    ListNode* mid = midL(head);
    ListNode* newHead = mid->next; //handling odd inkedlist case also
    mid->next=NULL;  // new head becomes tail
    newHead = reverse(newHead); // reverse 
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

}; */


//SOLUTION 2 
class Solution {
public:
    
    ListNode* getMid(ListNode* head)
    {
        ListNode *slow,*fast;
        slow = fast = head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
    
    ListNode* getReverse(ListNode* head)
    {
        ListNode *cur,*prev;
        cur=head;
        prev = NULL;
        while(cur!=NULL)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        //  If Linked List contains less than 3 nodes then no need to do anything.
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return;
        
        /*  
            Get Middle Node
            If there is two middle node then return first Middle.
        */
        ListNode* mid = getMid(head);
        
        //  Seprate the Second Half of the LinkedList
        ListNode* secondHalf = mid->next;
        mid->next=NULL;
        
        //  Reverse the Second Half of LinkedList
        ListNode* revHalf = getReverse(secondHalf);
        
        //  Finally Merge in Required Manner
        while(head!=NULL&&revHalf!=NULL)
        {
            ListNode* temp = head->next;
            head->next=revHalf;
            revHalf=revHalf->next;
            head->next->next=temp;
            head = temp;
        }
    }
}; 