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
    int min_diff = INT_MAX , val =-1;
    int inorder(TreeNode* root)
    {
        
        if(root->left!=NULL)
          inorder(root->left );
            if(val>=0)
            {
                min_diff = min(min_diff, root->val - val);
               
            }
            val = root->val;
            if(root->right!=NULL)
            inorder(root->right);
        return min_diff;
        }
    
    int minDiffInBST(TreeNode* root) {
       return inorder(root); 
    }
};

//In-order traversal of BST yields sorted sequence. So, we just need to subtract the previous element from the current one, and keep track of the minimum. We need O(1) memory as we only store the previous element, but we still need O(h) for the stack.