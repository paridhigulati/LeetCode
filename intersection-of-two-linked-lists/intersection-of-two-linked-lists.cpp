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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
ListNode* cur = headA;
        int lenA = 0;
        while(cur != NULL){
            lenA ++;
            cur = cur->next;
        }

        cur = headB;
        int lenB = 0;
        while(cur != NULL){
            lenB ++;
            cur = cur->next;
        }
        ListNode* curA = headA;
        ListNode* curB = headB;
        if(lenA > lenB) {
            for(int i=0; i<lenA-lenB; i++){
                curA = curA->next;
            }
        }
        if(lenA < lenB)  {
            for(int i=0; i<lenB-lenA; i++){
                curB = curB->next;
            }
        }
        while(curA!=NULL){
            if(curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    
    }
};