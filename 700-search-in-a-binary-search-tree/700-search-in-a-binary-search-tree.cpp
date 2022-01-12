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
   
TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return nullptr;
    while(root)
    {
        if(root->val == val)
            
            return root;
    
        else if(root->val > val)
        {
            //if(root->left!=NULL)
        
         root= root->left;
        }
    
        else
        {
            if(root->val < val)
            {
              //  if(root->right!=NULL)
              //  {
                 root= root->right; 
               // }
            }
        }
    }
    return root;
    }
};
     
	
        