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
    ListNode* reverseList(ListNode* head) {
        //recursive
//         if(!head || !(head->next)) return head;
//         ListNode* temp = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return temp;
//     }
// };
      

    ListNode* prev = NULL , *curr = head, *fwd;
        
        while(curr)
        {
            fwd = curr->next;
            curr->next = prev;
             prev = curr;
              curr = fwd; 
        }
        return prev;
    }
        
        
};
 