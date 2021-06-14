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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)return head;

        // Eg: 1 -> 2 -> 3 -> 4-> 5 , m = 2 n = 4

        // first set pre and cur by moving m-1 times
        ListNode* pre = NULL, *cur = head;
        for(int i = 1; i <= m-1; ++i){ // 1 time
            pre = cur;
            cur = cur->next;
        }

        // 1 -> 2 -> 3 -> 4-> 5 (now pre = 1, cur = 2)
        ListNode* con = pre, *tail = cur; // two extra pointers to set the connection after reversal
        // con = 1, tail = 2 (since after reversal from 2 to 4, 2 will be tail of the reversed list)
        // con can remain null if m = 1, edge case

        // reverse the link (loop will run n-m+1 times)
        ListNode* third = NULL;
        for(int i = 1; i <= n-m+1; ++i){
            third = cur->next;
            cur->next = pre;
            pre = cur;
            cur = third;
        }

        // until now  1 <- 2 <- 3 <- 4  5 (pre = 4, cur = 5, con = 1, tail = 2)
        // build the connection 
        if(con){
            con->next = pre;
        }
        else{
            head = pre; // edge case (m = 1)
        }
        tail->next = cur;
        // finally 1 -> 4 -> 3 -> 2 -> 5 

        return head;
    }

};