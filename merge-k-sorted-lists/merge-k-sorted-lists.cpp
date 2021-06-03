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
        
        //APPROACH 1 TC= O(KN) SC = O(1)  merge 2 LL (k-1) times

ListNode *merge(ListNode* a, ListNode* b){
    
    if(!a)
        return b;
    
    if(!b)
        return a;
        
    ListNode *res;
    
    if(a->val<b->val){
        res=a;
        res->next=merge(a->next,b);
    }
    else{
        res=b;
        res->next=merge(a,b->next);
    }
        
    return res;
}

ListNode *util(vector<ListNode*>& lists, int i){
    
    if(i+1==lists.size())
        return lists[i];
    
    return merge(lists[i],util(lists,i+1));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    if(lists.size()==0)
        return NULL;
    
    return util(lists,0);
}
};
        
        
        
    


