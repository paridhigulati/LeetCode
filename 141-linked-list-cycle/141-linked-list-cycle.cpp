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
    bool hasCycle(ListNode *head) {
     
        if(!head) return false;
        
        ListNode* slow= head, *end = head;
        
        while( end!=NULL and end->next != NULL)
        {
            end = end->next->next;
            slow = slow->next;
        
        if(slow == end)
            return true;
        }
        return false;
    }
};