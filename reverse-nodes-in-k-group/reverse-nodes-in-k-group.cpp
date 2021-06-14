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
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
    
    
        ListNode* before = dummy;
        ListNode* after = head;
    
    
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* fwd = nullptr;
        while(true){
            ListNode* cursor = after;
            for(int i = 0; i < k; i++){
                if(cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }
            curr = after;
            prev = before;
            for(int i = 0; i < k; i++){
                fwd = curr->next;
                curr->next = prev;
                prev = curr;
                curr = fwd;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
}; */
    ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *ptr = head, *prev = new ListNode(0),
             *start, *end, *temp;

    int size = 0, count = 0;

    // Getting the size of the List
    while (ptr)
    {
        ptr = ptr->next;
        size++;
    }

    int it = 0;
    ptr = head;
    prev->next = ptr;
    start = prev;

    // State (k=3) : start/prev -> 1 -> 2 -> 3 -> 4....... 6 -> NULL

    while (ptr)
    {
        // If number of remaining elements is less than k OR
        // If there are k more elements remaining
        if ((it + 1) * k > size)
            break;

        // Reversing the next k elements in list
        count = 0;
        while (count < k && ptr)
        {
            temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
            count++;
        }

        // State (k=3,it=0) : start <- 1 <- 2 <- 3(prev)  4 -> ....... 6 -> NULL

        // Reversing the k-group of elements in list
        end = prev;
        temp = start->next;
        start->next = end;
        start = temp;
        start->next = ptr;

        // State (k=3,it=0) : start -> 3 -> 2 -> 1 -> 4 -> ....... 6 -> NULL

        // If start was the head, making end pointer the head
        if (!it)
            head = end;
        // State (k=3) : start/prev/head -> 3 -> 2 -> 1 -> 4 -> ....... 6 -> NULL

        it++;
    }
    return head;
}
};