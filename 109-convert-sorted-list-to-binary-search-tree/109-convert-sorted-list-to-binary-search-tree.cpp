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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail = NULL) {
        
     if(head ==tail) return NULL;
        
        ListNode* fast = head, *slow = head;
        while(fast!=tail and fast->next != tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode* tmp = new TreeNode(slow->val);
        
        tmp->left = sortedListToBST(head, slow);
        tmp->right = sortedListToBST(slow->next, tail);
        
        return tmp;
    }
};
           