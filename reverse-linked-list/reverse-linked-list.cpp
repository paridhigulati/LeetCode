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
    /*
    //iterative O(n) time and O(1)space 
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL || head->next==NULL) //zero or a single node 
            return head;
        ListNode* prev = NULL;
        ListNode* curr=head;
        ListNode* fwd = NULL; 
        while(curr!=NULL)
        {        
        fwd = curr->next; // backup so that remaining list is not lost while reversing 
        curr->next=prev; // 1->2 ===> 1<-2
        prev = curr;
        curr = fwd;
        }
        return prev;
    }
};
    */
// recursive O(n) time but O(n) space too
    ListNode* reverseList(ListNode* head) 
        {
        if(head==NULL|| head->next==NULL ) 
        {
            return head;
        }
        ListNode* p = reverseList(head->next); // reversing all the nodes after head
        head->next->next = head; //reversing the next of the nodes from back     1->2 where head = 1 will now become 1<-2
        head->next=NULL; // the original head now becomes null i.e tail node 
        return p;
    }
    
};