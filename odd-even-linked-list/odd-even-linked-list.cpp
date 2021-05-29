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
 
           ListNode* oddEvenList(ListNode* head) {
               if(head==NULL ||head->next==NULL)
                   return head;
        // dummy head nodes are odd and even lists
        ListNode *odd_head = new ListNode(-1), *even_head = new ListNode(-1);
        // tail nodes for odd and even lists
        ListNode *odd_tail = odd_head, *even_tail = even_head;
        
        int pos = 0;
        // temp ptr foor traversal
        ListNode* iter = head;
        while(iter) {
           ++pos;
            // add the odd node
            if(pos % 2 != 0) {
                odd_tail->next = iter;
                odd_tail = odd_tail->next;
            }
            // add tthe even node
            else {
                even_tail->next = iter;
                even_tail = even_tail->next;
            }
            // go to next node
            iter = iter->next;
        }
        // terminate the individual lists
        //odd_tail->next = nullptr,
               even_tail->next = nullptr;
        // add the odd and even lists together
        odd_tail->next = even_head->next;
        return odd_head->next;
     }
};
      /*  if(head==NULL || head->next==NULL)
            return head;
        ListNode* oDummy = new ListNode(-1);
        ListNode* eDummy = new ListNode(-1);
          ListNode* etail = eDummy;
            ListNode*  otail = oDummy;
          ListNode* node = head;
        while(node)
        {
        if(node->val%2==0)
        {
            etail->next = node;
            etail = etail->next;
        }
        else
        {
            otail->next = node;
            otail=otail->next; 
        }
        
            node=node->next;
            
        
            otail->next = eDummy->next;
        
                etail->next=NULL;
        }
            return oDummy;
    }
}; */