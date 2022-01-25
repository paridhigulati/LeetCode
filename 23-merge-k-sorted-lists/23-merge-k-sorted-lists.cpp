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


        //MIN HEAP SOLUTION 
       
        // Initially added heads of all the lists in the heap. In the first iteration, pop from heap would given minimum element and then we will push the next element of list we popped from and the process continues till all nodes are added in our answer list.
class comparator{
    public:
    bool operator()(ListNode *x,ListNode *y){
        return (x->val>y->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comparator> pq;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *tail=dummy;
        
        while(!pq.empty()){
            ListNode *top=pq.top();
            pq.pop();
            tail->next=top;
            tail=tail->next;
            if(top->next)
                pq.push(top->next);
        }   
        return dummy->next;
    }
};
