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
    ListNode* deleteDuplicates(ListNode* head) {
     
        ListNode* tmp = head;
        if(!head || !head->next) return head;
        while(tmp and tmp->next)
        {
            
            if(tmp->val == tmp->next->val)
            {
                ListNode* del = tmp->next;
                tmp->next = del->next;
                delete(del);
                
            }
            else
                tmp=tmp->next;
            
            
        }
        return head;
    }

};