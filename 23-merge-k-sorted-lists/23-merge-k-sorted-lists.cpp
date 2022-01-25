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
        //MIN HEAP SOLUTION 
       
        // Initially added heads of all the lists in the heap. In the first iteration, pop from heap would given minimum element and then we will push the next element of list we popped from and the process continues till all nodes are added in our answer list.
        
         struct node {
        ListNode *curr;    //Current node
        int idx;    //List index number
        node(ListNode *a,int b)
        {
            curr = a;
            idx = b;
        }
    };
    struct compare {
    bool operator()(node a, node b)
    {
        return a.curr->val >b.curr->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0)
            return NULL;
        ListNode *head,*tail;
        head=tail=NULL;
        priority_queue<node,vector<node>,compare> heap;
        vector<ListNode*> ptr(k);   //Current node ptrs for all the lists
        //Assign all the current ptrs and BUILD_HEAP
        for(int i=0;i<k;++i)
        {
            ptr[i]=lists[i];
            if(ptr[i]!=NULL)
                heap.push(node(ptr[i],i));
        }
        
        if(heap.empty())
            return NULL;
        //Insert 1st node
        head=tail=heap.top().curr;
        int idx = heap.top().idx;
        heap.pop();
        ptr[idx]=ptr[idx]->next;
        if(ptr[idx])    //Push newly pointed node if not NULL
            heap.push(node(ptr[idx],idx));
        
        //Make list with rest of the nodes
        while(!heap.empty())
        {
            ListNode *temp=heap.top().curr; //Pop root node
            idx=heap.top().idx;
            heap.pop();
            
            tail->next=temp;    //Add newnode to list
            tail=tail->next;
            ptr[idx]=ptr[idx]->next;    //Update current pointer
            if(ptr[idx])   //Push newly pointed node if not NULL
                heap.push(node(ptr[idx],idx));
        }
        return head;
    }
};