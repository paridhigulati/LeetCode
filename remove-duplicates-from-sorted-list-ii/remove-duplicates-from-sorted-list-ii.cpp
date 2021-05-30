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
        if(head==nullptr|| head->next==nullptr)
            return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy; //iterator 
        while(head)
        {
        if(head->next&& head->val == head->next->val)
        {
            int curr = head->val;
            while(head && head->val == curr)
            {
                head=head->next;
            }
        }
        else {
        temp->next= head;
        temp = head;
        head= head->next;
        }
        }
     temp->next = nullptr;
        return dummy->next;
    }
};